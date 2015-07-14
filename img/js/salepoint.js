            $(function() {
                $( "#dialog" ).dialog({
                    title:"Внимание",
                    width:850,
                    height: 'auto',
                    modal: true,
                    autoOpen: false,
                    buttons: {
                        "Закрыть": function(){
                                        $(this).dialog('close');
                                        $(this).text('');
                                    }
                    }
                });
            });

            function hoverImg(elem){
                // по событию ommousedown меняем картинку
                    $(elem).attr('src', $(elem).attr('src').substring(-1,$(elem).attr('src').length-5)+'2.png')

            }
            function removeBlock(callback){

                $('#content').children('.block').each(function(){
                    var cl = $(this).attr('class').split(' ')[1]
                    if(cl !== 'kassa' & cl !== 'viewcells' & cl !== 'card'){
                        alert(cl)
                        $(this).remove()
                    }
                    else{
                        $(this).css('display', 'none')
                    }
                })
                callback();
            }
            function showMap(){
                sale_cell.hole = 1;
                        begin = 1
                        end = 10
                        data = foo.get_cells('1', begin, end, 0);
                        $('.viewcells').css({"display":"block"});
                        $('.chour').text('0')
                        free_cells=0;
                        $('.holl').children('.row').remove();
                        for(i=1; i<=10; i++){
                            $('.holl').append('<div class="row '+i+'" sec_index="'+i+'"></div>')
                        }
                        $(data).find('item').each(function(){
                            if ($(this).attr('state')=='free'){
                                free_cells+=1
                            }
                            if ($(this).attr('cell_num')!='99999'){
                                class_name='need_pay'
                                size = $(this).attr('cell_size')
                                if($(this).attr('need_pay')=='yes'){
                                    class_name='need_pay'
                                }
                                else {
                                    class_name=$(this).attr('state')
                                }
                                $('.'+$(this).attr('sec_index')).append("<div class='cell size"+size+"_"+class_name+"'>"+
                                $(this).attr('cell_num')+"</div>")
                            }
                        })
            }

            function showMenu(){
                //<!--  Создаем основное меню -->
                /*
                    Сначала грохаем всех детей родительского узла
                */


                // прячем блок kassa
                $('#content').append($('<div/>')
                                        .addClass('block')
                                        .addClass('menu')
                                        .css({'padding-top':'20px','display':'block'})
                                        .append($('<div/>')
                                                .addClass('button')
                                                .css({'margin':'auto','width':'100%','height':'150px'})

                                                .append($('<img/>')
                                                    .attr('src','bt_oper1.png')
                                                    .attr('cmd', 'oper')
                                                    .mousedown(function(){
                                                        hoverImg(this)
                                                    })
                                                    .mouseup(function(){
                                                        $('#dialog').dialog({
                                                            buttons: {
                                                                "Войти": function(){
                                                                    $('#dialog').dialog('close')
                                                                    removeBlock(showMenuOper)
                                                                },
                                                                "Close":function(){
                                                                    $('#dialog').dialog('close')
                                                                }
                                                            }
                                                        })
                                                        $('#dialog').dialog('open')
                                                        //showMenuOper(this)
                                                    })
                                                 ))
                                        .append($('<div/>')
                                                .addClass('button')
                                                .css({'margin':'auto','width':'100%','height':'150px'})

                                                .append($('<img/>')
                                                    .attr('src','bt_admin1.png')
                                                    .attr('cmd', 'admin')
                                                    .mousedown(function(){
                                                        hoverImg(this)
                                                    })
                                                 ))
                                        .append($('<div/>')
                                                .addClass('button')
                                                .css({'margin':'auto','width':'100%','height':'150px'})

                                                .append($('<img/>')
                                                    .attr('src','bt_tech1.png')
                                                    .attr('cmd', 'tech')
                                                    .mousedown(function(){
                                                        hoverImg(this)
                                                    })
                                                 ))
                                        .append($('<div/>')
                                                .addClass('button')
                                                .css({'margin':'auto','width':'100%','height':'150px'})

                                                .append($('<img/>')
                                                    .attr('src','bt_map1.png')
                                                    .attr('cmd', 'map')
                                                    .mousedown(function(){
                                                        hoverImg(this)
                                                    })
                                                 ))
                                    )



            }


            function showMenuOper(){
                /*var cmd = new Object()
                cmd.cmd = $(elem).attr('cmd')
                cmd.parent_class = $(elem).parent().parent().attr('class').split(' ')[1]
                cmd.html = $(elem).parent().parent().html()
                alert(cmd.html)*/
                $('#content').children('.block').remove();
                $('#content').append($('<div/>')
                                        .addClass('block')
                                        .addClass('oper')
                                        .css({
                                                'display':'block',
                                                'padding-top':'20px'
                                            })
                                        .append($('<div/>')
                                                .addClass('button')
                                                .css({'margin':'auto','width':'50%','height':'150px','float':'left'})
                                            .append($('<img/>')
                                               .attr('src', 'bt_sale1.png')
                                               .mousedown(function(){
                                                    hoverImg(this);
                                               })
                                               .mouseup(function(){
                                                    $(this).remove()
                                                    showMenu()
                                               })

                                            ))
                                        .append($('<div/>')
                                                .addClass('button')
                                                .css({'margin':'auto','width':'50%','height':'150px','float':'left'})
                                            .append($('<img/>')
                                                .attr('src', 'bt_wc1.png')
                                                .mousedown(function(){
                                                    hoverImg(this);
                                                })
                                            ))
                                        .append($('<div/>')
                                                .addClass('button')
                                                .css({'margin':'auto','width':'50%','height':'150px','float':'left'})
                                            .append($('<img/>')
                                                .attr('src', 'bt_return1.png')
                                                .mousedown(function(){
                                                    hoverImg(this);
                                                })
                                            ))
                                        .append($('<div/>')
                                                .addClass('button')
                                                .css({'margin':'auto','width':'50%','height':'150px','float':'left'})
                                            .append($('<img/>')
                                                .attr('src', 'bt_bsk1.png')
                                                .mousedown(function(){
                                                    hoverImg(this);
                                                })
                                            ))
                                        .append($('<div/>')
                                                .addClass('button')
                                                .css({'margin':'auto','width':'50%','height':'150px','float':'left'})
                                            .append($('<img/>')
                                                .attr('src', 'bt_kassa1.png')
                                                .mousedown(function(){
                                                    hoverImg(this);
                                                })
                                            ))
                                        .append($('<div/>')
                                                .addClass('button')
                                                .css({'margin':'auto','width':'50%','height':'150px','float':'left'})
                                            .append($('<img/>')
                                                .attr('src', 'bt_mobile1.png')
                                                .mousedown(function(){
                                                    hoverImg(this);
                                                })
                                            ))
                                        .append($('<div/>')
                                                .addClass('button')
                                                .css({'margin':'auto','width':'50%','height':'150px','float':'left'})
                                            .append($('<img/>')
                                                .attr('src', 'bt_map1.png')
                                                .attr('cmd', 'get_cell')
                                                .attr('begin', '1')
                                                .attr('end', '10')
                                                .mousedown(function(){
                                                    hoverImg(this);
                                                })
                                                .mouseup(function(){
                                                    removeBlock(showMap)
                                                })
                                            ))
                                        .append($('<div/>')
                                                .addClass('button')
                                                .css({'margin':'auto','width':'50%','height':'150px','float':'left'})
                                            .append($('<img/>')
                                                .attr('src', 'bt_backw1.png')

                                                .mousedown(function(){
                                                    hoverImg(this);
                                                })
                                               .mouseup(function(){
                                                    $(this).remove()
                                                    removeBlock(showMenu)
                                               })
                                            ))
                                    )
            };


            var content = '';
            var card='';
            var read=1;
            function jgetcard(){
                    if (window.read==1){
                        var data = foo.getcard().toUpperCase();
                        data=data.replace(/^0+/, '')
                        $("#scontent").children('h2').remove();
                        $('#scontent').append("<h2>"+data+"</h2>")
                        window.card=data
                        if(data!="NONE_DATA"){
                            window.read=0;
                        }
                    }
            }
            function info_elem(elem,data){
                var cell_num = $(data).attr('cell_num')
                if($(data).attr('adm_cell')=='yes'){
                    cell_num+='A'
                }
                $(elem).append($('<div/>')
                                 .addClass("cell size"+size+"_"+class_name)
                                .attr({
                                        'state':$(data).attr('state'),
                                        'sec_num':$(data).attr('sec_num'),
                                        'cell_index':$(data).attr('cell_index'),
                                        'hall':$(data).attr('hall'),
                                        'sec_index':$(data).attr('sec_index'),
                                        'cell_size':$(data).attr('sell_size'),
                                        'cell_num':$(data).attr('cell_num'),
                                        'active':$(data).attr('active'),
                                        'need_pay':$(data).attr('need_pay'),
                                        'cell_pos':$(data).attr('cell_pos'),
                                        'card':$(data).attr('card'),
                                        'act_time':$(data).attr('act_time'),
                                        'end_time':$(data).attr('end_time'),
                                        'pay_time':$(data).attr('pay_time'),
                                        'pay_sum':$(data).attr('pay_sum'),
                                        'adm_cell':$(data).attr('adn_cell'),
                                        'isfree':$(data).attr('isfree'),
                                        'root_access':$(data).attr('root_access'),

                                      })
                                .text(cell_num)
                                .click(function(e){
                                    if($(this).attr('need_pay')=='yes'){
                                        var text = 'Доплата за: '+parseInt($(this).attr('pay_time'))/60+'ч.<br>'
                                        text+='Составляет: '+ $(this).attr('pay_sum').substr(0, $(this).attr('pay_sum').length-2)+'руб.<br>'
                                        text+='Оплачено с: ' + $(this).attr('act_time')
                                        text+='<br>По: '+$(this).attr('end_time')


                                    }
                                    else if($(this).attr('state')=='free'){
                                        $('.cell_num').text($(this).attr('cell_num'))
                                        $('.block').css({"display":"none"});
                                        $('.chour').text('0')
                                        $('.kassa').css({"display":"block"})

                                    }
                                    else {
                                        var text='Оплачено с: ' + $(this).attr('act_time')
                                        var act_time = $(this).attr('act_time').replace(/\.|-|:/g,',').replace(/\,0/g,',').split(',')
                                        var end_time = $(this).attr('end_time').replace(/\.|-|:/g,',').replace(/\,0/g,',').split(',')
                                        var end = new Date()
                                        end.setFullYear(end_time[0])
                                        end.setMonth(end_time[1]-1)
                                        end.setDate(end_time[2])
                                        end.setHours(end_time[3])
                                        end.setMinutes(end_time[4])
                                        end.setSeconds(end_time[5])

                                        //var end_time = new Date($(this).attr('end_time'))
                                        var now = new Date()
                                        var diff = end-Date.now()
                                        text+='<br>По: '+$(this).attr('end_time')
                                        timer = diff/1000/60/60+''.substr(0,3)
                                        hour = timer.split('.')[0]
                                        minut = 60*parseFloat('0.'+timer.split('.')[1])+''
                                        minut = minut.substr(0,2).replace('.','')
                                        text+='<br>Осталось: '+hour+'ч.'+minut+'мин.'
                                        var admin = 'разрешен'
                                        if($(this).attr('root_access')=='no'){
                                            admin = 'запрещен'
                                            $('#dialog').dialog({
                                                buttons: {
                                                    "Разрешить админ": function(){
                                                        $('#dialog').dialog('close')
                                                    },
                                                    "Закрыть": function(){
                                                        $('#dialog').dialog('close')
                                                    }
                                                }
                                            })
                                        }
                                        text+='<br>Админ: '+admin
                                    }
                                    if($(this).attr('state')!='free'){
                                        $('#dialog').html(text)
                                        $('#dialog').dialog('open')
                                        $('#dialog').dialog({title:'Ячейка: '+$(this).attr('cell_num')})
                                    }

                                           })
                                    )

            }
            var sale_cell = new Object()
                sale_cell.card = '';
                sale_cell.sec_num = '';
                sale_cell.cell_index = '';
                sale_cell.btime = '';
                sale_cell.sum = '';
                sale_cell.kkmses = '';
                sale_cell.kkmcheck = '';
                sale_cell.hole = 1;
                sale_cell
                sale_cell.buy_card = function(){
                    alert('buy_card: card, btime, sum, kkmses, kkmcheck, sec_num, cell_index')
                }

            function viewcell(hal, begin, end){
                data = foo.get_cells(hal, begin, end, 0);
                        free_cells=0;
                        $('.holl').children('.row').remove();
                        if (begin < 0){
                            begin =1
                        }
                        if (end > 35){
                            end=35
                        }
                        for(i=parseInt(begin); i<=parseInt(begin)+10; i++){
                            $('.holl').append('<div class="row '+i+'" sec_index="'+i+'"></div>')
                        }
                        $(data).find('item').each(function(){
                            if ($(this).attr('state')=='free'){
                                free_cells+=1
                            }
                            if ($(this).attr('cell_num')!='99999'){
                                class_name='need_pay'
                                size = $(this).attr('cell_size')
                                if($(this).attr('need_pay')=='yes'){
                                    class_name='need_pay'
                                }
                                else {
                                    class_name=$(this).attr('state')
                                }
                                info_elem($('.'+$(this).attr('sec_index')),$(this))
                            }
                        })
                        $('.free_cells').text(free_cells)




            }
            function onclickmenu(){
                    $('#content').find('.block').first().children('div').find('img').each(function(){
                        if($(this).attr('cmd') == 'oper'){

                            $(this).click(function(){
                                showMenuOper(this)
                            })
                        }
                    })
                }




            function setdatetime(){
                var data = foo.setdatetime()
                var month_names=['января', "февраля", "марта", "апреля", "майя", "июня", "июля", "августа", "сентября",
                                "октября", "ноября", "декабря"]
                $('#date').text($(data).find('day').text()+' '+month_names[parseInt($(data).find('month').text())]+' '+
                                $(data).find('year').text());
                $('#time').text($(data).find('time').text());
            }
            $(document).ready(function(){





                onclickmenu();
                showMenu();


                sale_cell.buy_card()
                sale_cell.card='99999'
                $('.numbutton').mousedown(function(){
                    $(this).css({"background-image":$(this).css('background-image').substring(0,$(this).css('background-image').length-6)+'2.png)'})
                });
                $('.hol').mouseup(function(){
                    if($(this).attr('cmd') == 'hol_next'){
                        sale_cell.hole=parseInt(sale_cell.hole+1).toString()
                        begin = parseInt(sale_cell.hole)*10+1
                        end= begin+9
                        viewcell('1', begin, end)

                    }
                    else if($(this).attr('cmd') == 'hol_back'){
                        sale_cell.hole=parseInt(sale_cell.hole-1).toString()
                        if(parseInt(sale_cell.hole)<0){
                            sale_cell.hole=0;
                        }
                        end = parseInt(sale_cell.hole)*10
                        begin= end-9
                        data = foo.get_cells('1', begin, end, 0);
                        viewcell('1', begin, end)

                    }
                        $('.free_cells').text(free_cells)
                    sale_cell.hole = parseInt(sale_cell.hole)

                })
                $('.numbutton').mouseup(function(){
                    $(this).css({"background-image":$(this).css('background-image').substring(0,$(this).css('background-image').length-6)+'1.png)'})
                    /* Вызывать функцию выбора ячеек */
                    if($(this).attr('cmd')=='get_cell'){
                        sale_cell.hole = 1;
                        begin = $(this).attr('begin')
                        end = $(this).attr('end')
                        data = foo.get_cells('1', begin, end, 0);
                        $('.block').css({"display":"none"});
                        $('.viewcells').css({"display":"block"});
                        $('.chour').text('0')
                        free_cells=0;
                        $('.holl').children('.row').remove();
                        for(i=1; i<=10; i++){
                            $('.holl').append('<div class="row '+i+'" sec_index="'+i+'"></div>')
                        }
                        $(data).find('item').each(function(){
                            if ($(this).attr('state')=='free'){
                                free_cells+=1
                            }
                            if ($(this).attr('cell_num')!='99999'){
                                class_name='need_pay'
                                size = $(this).attr('cell_size')
                                if($(this).attr('need_pay')=='yes'){
                                    class_name='need_pay'
                                }
                                else {
                                    class_name=$(this).attr('state')
                                }
                                info_elem($('.'+$(this).attr('sec_index')),$(this))
                            }

                        })
                        $('.free_cells').text(free_cells)



                    }
                    else if($(this).attr('cmd')=='clear'){
                        $('.chour').text('0')
                        $('.cell_num').text('')
                    }
                    else if($('.chour').text()=='0'){
                        $('.chour').text($(this).text())
                    }
                    else {
                        $('.chour').text($('.chour').text()+$(this).text())
                    }

                });
                $('img').mousedown(function(){
                    $(this).attr('src', $(this).attr('src').substring(0,$(this).attr('src').length-5)+'2.png')
                });
                $('img').mouseup(function(){
                    if ($(this).attr('class')=='none'){
                        $(this).attr('src', $(this).attr('src').substring(0,$(this).attr('src').length-5)+'1.png')
                        return None;
                    }
                    $('#content').css({"background-color":"white"})
                    $('#footer').css({"display":"block"});
                    $(this).attr('src', $(this).attr('src').substring(0,$(this).attr('src').length-5)+'1.png')
                    var cmd = $(this).attr('cmd')
                    if (cmd=='tech') {
                        foo.quit();
                    }
                    else if (cmd== "getcard"){
                        var data = foo.getcard().toUpperCase();
                        $("#scontent").children('h2').remove();
                        $('#scontent').append("<h2>"+data+"</h2>")
                    }
                    else if (cmd == "sale"){
                        $('.block').css({"display":"none"});
                        $('.kassa').css({"display":"block"});
                        $('#footer').css({"display":"none"});
                        $('#content').css({"background-color":"#C9D6E0"})
                        window.read=1;
                    }
                    else if (cmd == "back_menu_oper"){
                        $('.block').css({"display":"none"});
                        $('.chour').text('0')
                        $('.oper').css({"display":"block"})
                    }
                    else if (cmd == "back_menu_kassa"){
                        $('.block').css({"display":"none"});
                        $('.kassa').css({"display":"block"})
                    }
                    else if (cmd=='back'){
                        $('.block').css({"display":"none"});
                        $('.menu').css({"display":"block"});
                        $("#hcontent").children('h2').remove()
                    }
                    else if (cmd=='map'){

                        sale_cell.hole = 1;
                        begin = 1
                        end = 10
                        data = foo.get_cells('1', begin, end);
                        $('.block').css({"display":"none"});
                        $('.viewcells').css({"display":"block"});
                        $('.chour').text('0')
                        free_cells=0;
                        $('.holl').children('.row').remove();
                        for(i=1; i<=10; i++){
                            $('.holl').append('<div class="row '+i+'" sec_index="'+i+'"></div>')
                        }
                        $(data).find('item').each(function(){
                            if ($(this).attr('state')=='free'){
                                free_cells+=1
                            }
                            if ($(this).attr('cell_num')!='99999'){
                                class_name='need_pay'
                                size = $(this).attr('cell_size')
                                if($(this).attr('need_pay')=='yes'){
                                    class_name='need_pay'
                                }
                                else {
                                    class_name=$(this).attr('state')
                                }
                                $('.'+$(this).attr('sec_index')).append("<div class='cell size"+size+"_"+class_name+"'>"+
                                $(this).attr('cell_num')+"</div>")
                            }
                        })

                    }
                    /*else if (cmd=='oper'){
                        var data = foo.ping(0);
                        $('.menu').css({"display":"none"})
                        $('.oper').css({"display":"block"})



                        $(data).find('header').each(function() {
                            data=$(this).find('type').text()
                            if (data=="server_not_foun"){
                                $("#hcontent").children("h2").remove()
                                $("#hcontent").css({"color":"#ffffff"})
                                $("#header").css({"background-color":"red","background-image":"none"})
                                $("#hcontent").append("<h2>Код ошибки 2. Сервер не найден</h2>")
                            }
                            else {
                                $("#hcontent").children("h2").remove()
                                free_cells=$(this).find('free_cells').text()
                                $("#free_cells").text(free_cells)
                                $("#hcontent").append("<h2>Ответ сервера:</h2>")
                            }
                        });
                    }*/
                });


                setInterval('setdatetime();', 1000);
                setInterval('jgetcard();',5000);
                $('#settings').click(function (){
                    if ($("#scontent").css('display')=='none') {
                        $('#scontent').slideDown('slow')
                    }
                    else {
                        $('#scontent').hide('slow')
                    }
                });


            });
