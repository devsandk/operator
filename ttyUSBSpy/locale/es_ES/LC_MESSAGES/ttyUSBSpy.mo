��          �      ,      �     �  �  �     P     X     i     n     v          �     �  	   �     �     �     �     �  	   �  ,  �        >       A     J     [     `     h     o     �     �  
   �     �     �     �     �  	   �                                             	   
                              - <p><b>ttyUSBSpy</b> decodes pcap files captured by por tcpdump

from serial port (tcpdump uses usbmon module to capture data, so 

ttyUSBSpy only works with USB-RS232 conversor).</p>  

<p>Grid shows hexadecimal data in the serial port

 except in cases where appears"|", this indicates a change 

 in the signals RTS/CTS, clicking shows the value in the modem line status</p>

<p>Captured data shows, Rs232 comunication and the comms

of the SO with the usb-Rs232 conversor chip. So we have 

to choose the Dev number that identifies the Rs232 port

to filter the comms with the chip. </p>

<p><b>METHOD OF USE:</b></p>

<p> Left mouse button shows the time (T1) and the status of the byte or signal</p>

<p> Right mouse button shows the time (T2) and the status of the byte or signal 

and delta time (T2-T1) in milliseconds</p>

<p> Send bytes or signals are shown in blue </p>

<p> Received bytes or signals are shown in green</p>

<p> Selected bytes or signals are shown in red </p>



<p>It is running on version %(wxpy)s of <b>wxPython</b> and %(python)s of <b>Python</b>.

See <a href="http://wiki.wxpython.org">wxPython Wiki</a></p>

<b>ttyUSBViewer</b> is based on the dwaley/ USB Reverse Engineering Software  Capture Delta(T2-T1)(ms) Dev: End(T2) Languaje Modem Line Status Select File Select File: Start(T1) Stop Times file tool ttyUsbSpy Project-Id-Version: PACKAGE VERSION
Report-Msgid-Bugs-To: 
POT-Creation-Date: 2013-04-05 09:49+0200
PO-Revision-Date: 2013-04-05 09:57+0100
Last-Translator: kogar
Language-Team: LANGUAGE <LL@li.org>
Language: 
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
 - <p><b>ttyUSBViewer</b> decodifica los paquetes pcap capturados por tcpdumpdel puerto serie (tiene que ser a traves de un conversor USB-RS232, ya que el tcpdumpusa el modulo usbmon para capturar los datos).</p>  <p> Los datos en el grid suelen ser datos hexadecimales que se han transmitido porpuerto serie, salvo en los casos en los que aparece "|", esto indica un cambioen las seÃ±ales RTS/CTS, al pulsar encima nos indica este cambio en el Status</p><p>Los datos capturados incluyen los datos que salen por el puerto serie y las comunicaciones del Sistema Operativo con el chip del conversor usb-RS232, entonceshay q seleccionar el Dev que identifica al RS232 para filtrar las comms con el chip. </p><p><b>Modo de Empleo:</b></p><p> Pulsando boton izquierdo nos muestra el tiempo (T1) y el estado de ese  byte o seÃ±al</p><p> Pulsando boton derecho nos muestra el tiempo (T2) y el estado de ese  byte o seÃ±al y el tiempo T2-T1</p><p> Los bytes o seÃ±ales enviadas estan en color azul </p><p> Los bytes o seÃ±ales recibidos estan en color verde </p><p> Los bytes o seÃ±ales seleccionada esta en rojo </p><p>It is running on version %(wxpy)s of <b>wxPython</b> and %(python)s of <b>Python</b>.See <a href="http://wiki.wxpython.org">wxPython Wiki</a></p><b>ttyUSBViewer</b> is based on the dwaley/ USB Reverse Engineering Software Capturar Delta(T2-T1)(ms) Dev: Fin(T2) Idioma Modem Line Status Selecionar Fichero Selecionar Fichero: Inicio(T1) Fin Tiempos fichero tool ttyUsbSpy 