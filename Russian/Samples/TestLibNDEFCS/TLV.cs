using System;
using System.IO;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Linq;

namespace NdefLibrary.Ndef
{
    using TlvList = List<Tlv>;
 
    [ComVisible(false)]
    public class Tlv
    {
        public enum TlvType
        {
            Null = 0x00,
            LockControl = 0x01,
            MemoryControl = 0x02,
            NDEF = 0x03,
            Proprietary = 0xFD,
            Terminator = 0xFE
        };

        protected byte m_type;
        protected byte[] m_value;

        public byte[] addToByteArray(byte[] theArray, byte theNewByte)
        {
            byte[] newArray = new byte[theArray.Length + 1];
            theArray.CopyTo(newArray, 0);
            newArray[theArray.Length] = theNewByte;
            //theArray = newArray;

            return newArray;
        }

        //public static T[] SubArray<T>(this T[] data, int index, int length)
        //{
        //    T[] result = new T[length];
        //    Array.Copy(data, index, result, 0, length);
        //    return result;
        //}

        public Tlv(byte type, byte[] value = null)
        {
            value = value ?? new byte[0];

            m_type = type;
            m_value = value;
        }

        public byte type()
        {
            return m_type;
        }

        public UInt64 length()
        {
            switch ((TlvType)m_type)
            {
                case TlvType.Null:
                case TlvType.Terminator:
                    return 0;

                default:
                    return (UInt64)m_value.GetLength(0);
            }
        }

        public byte[] value()
        {
            switch ((TlvType)m_type)
            {
                case TlvType.Null:
                case TlvType.Terminator:
                    return new byte[0];

                default:
                    return m_value;
            }
        }

        public byte[] toByteArray()
        {
            byte[] buffer = new byte[0];

            switch ((TlvType)m_type)
            {
                case TlvType.Null:
                case TlvType.Terminator:
                    buffer = addToByteArray(buffer, m_type);
                    break;
                default:
                    {
                        buffer = addToByteArray(buffer, m_type);
                        UInt16 length = (UInt16)this.length();

                        if (length <= 0xFE)
                        {
                            buffer = addToByteArray(buffer, (byte)length);
                        }
                        else
                        {
                            buffer = addToByteArray(buffer, (byte)0xFF);
                            buffer = addToByteArray(buffer, (byte)(length >> 8));
                            buffer = addToByteArray(buffer, (byte)(length & 0xFF));
                        }

                        if (this.length() > 0)
                            buffer = buffer.Concat(m_value).ToArray();
                    }
                    break;
            }

            return buffer;
        }

        public static TlvList fromByteArray(byte[] data, UInt64 offset)
        {
            TlvList list = new TlvList();

            byte[] buffer = data.Take(data.Length - (int)offset).ToArray();
            UInt32 count = (UInt32)buffer.Length;
            UInt32 index = 0;

            while (count > index)
            {
                byte type = buffer[index];
                ++index;

                switch ((TlvType)type)
                {
                    case TlvType.Null:
                        break;

                    case TlvType.Terminator:
                    {
                        list.Add(createTerminatorTlv());
                        index = count;
                    }
                    break;

                    default:
                    {
                        if ((count - index) > 0)
                        {
                            UInt16 length = buffer[index];
                            ++index;

                            if (length > 0xFE)
                            {
                                length = 0;

                                if ((count - index) > 2)
                                {
                                    length = (UInt16)(((byte)(buffer[index]) << 8) | (byte)(buffer[index + 1]));
                                    index += 2;
                                }
                            }

                            if ((count - index) >= length)
                            {
                                list.Add(new Tlv(type, buffer.Skip((int)Math.Abs((int)index)).Take(length).ToArray()));
                                index += length;
                            }
                            else
                            {
                                index = count;
                            }
                        }
                    }
                    break;
                }
            }

            return list;
        }

        public static Tlv createNullTlv()
        {
            return new Tlv((byte)TlvType.Null);
        }

        public static Tlv createTerminatorTlv()
        {
            return new Tlv((byte)TlvType.Terminator);
        }

        public static Tlv createNDEFMessageTlv(NdefMessage msg)
        {
            return new Tlv((byte)TlvType.NDEF, msg.ToByteArray());
        }

        public static Tlv createNDEFMessageTlv(byte[] msgArray)
        {
            return new Tlv((byte)TlvType.NDEF, msgArray);
        }

        public static Tlv createEmptyNDEFMessageTlv()
        {
            return new Tlv((byte)TlvType.NDEF, new byte[0]);
        }

        public static Tlv createTestLockControlTlv()
        {
            return new Tlv((byte)TlvType.LockControl, new byte[] {0xA0, 0x10, 0x44});
        }
    }
}


/*
class Tlv;

typedef QList<Tlv> TlvList;

class LIBNDEFSHARED_EXPORT Tlv
{
public:
    enum TlvType
    {
        Null        = 0x00,
        NDEF        = 0x03,
        Terminator  = 0xFE
    };

protected:
    quint8 m_type;
    QByteArray m_value;

public:
    Tlv(quint8 type, const QByteArray& value = QByteArray());
    virtual ~Tlv();

    quint8 type() const;
    quint64 length() const;
    QByteArray value() const;

    QByteArray toByteArray() const;

    static TlvList fromByteArray(const QByteArray& data, quint64 offset = 0);

    static Tlv createNullTlv();
    static Tlv createTerminatorTlv();
    static Tlv createNDEFMessageTlv(const NDEFMessage& msg);
};





Tlv::Tlv(quint8 type, const QByteArray& value)
    :   m_type(type),
        m_value(value)
{
}

Tlv::~Tlv()
{
}

quint8 Tlv::type() const
{
    return m_type;
}

quint64 Tlv::length() const
{
    switch (m_type)
    {
        case Tlv::Null:
        case Tlv::Terminator:
            return 0;

        default:
            return m_value.count();
    }
}

QByteArray Tlv::value() const
{
    switch (m_type)
    {
        case Tlv::Null:
        case Tlv::Terminator:
            return QByteArray();

        default:
            return m_value;
    }
}

QByteArray Tlv::toByteArray() const
{
    QByteArray buffer;

    switch (m_type)
    {
        case Tlv::Null:
        case Tlv::Terminator:
            buffer.append(m_type);
            break;

        default:
        {
            buffer.append(m_type);
            quint16 length = this->length();

            if (length <= 0xFE)
            {
                buffer.append((quint8)length);
            }
            else
            {
                buffer.append((quint8)0xFF);
                buffer.append((quint8)(length >> 8));
                buffer.append((quint8)(length & 0xFF));
            }

            if (this->length() > 0)
                buffer.append(m_value);
        }
        break;
    }

    return buffer;
}

TlvList Tlv::fromByteArray(const QByteArray& data, quint64 offset)
{
    TlvList list;

    QByteArray buffer = data.left(data.count() - offset);
    qint32 count = buffer.count();
    qint32 index = 0;

    while (count > index)
    {
        quint8 type = buffer.at(index);
        ++index;

        switch (type)
        {
            case Tlv::Null:
                break;

            case Tlv::Terminator:
            {
                list.append(Tlv::createTerminatorTlv());
                index = count;
            }
            break;

            default:
            {
                if ((count - index) > 0)
                {
                    quint16 length = buffer.at(index);
                    ++index;

                    if (length > 0xFE)
                    {
                        length = 0;

                        if ((count - index) > 2)
                        {
                            length = (quint8(buffer.at(index)) << 8) | quint8(buffer.at(index + 1));
                            index += 2;
                        }
                    }

                    if ((count - index) >= length)
                    {
                        list.append(Tlv(type, buffer.mid(index, length)));
                        index += length;
                    }
                    else
                    {
                        index = count;
                    }
                }
            }
            break;
        }
    }

    return list;
}

Tlv Tlv::createNullTlv()
{
    return Tlv(Tlv::Null);
}

Tlv Tlv::createTerminatorTlv()
{
    return Tlv(Tlv::Terminator);
}

Tlv Tlv::createNDEFMessageTlv(const NDEFMessage& msg)
{
    return Tlv(Tlv::NDEF, msg.toByteArray());
}
*/