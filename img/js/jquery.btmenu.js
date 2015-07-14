(function($){
    jQuery.fn.btmenu = function(options){
        options = $.extend({
            firstCl:'block',
            secondCl:'menu',
            paddingTop:'20px',
            items:{
                class:'sds'
            }

        }, options);

        var make = function(){
        // здесь переменная this будет содержать отдельный
        // DOM-элемент, к которому и нужно будет применить
        // воздействия плагина
            alert(Object.keys(options.items).length)
           for(i=0; i<Object.keys(options.items).length; i++){
                alert(options.items.class)
              /*  $(this).append($('<div/>')
                                    .addClass(options.firstCl)
                                    .addClass(options.secondCl)
                                    .css({'padding-top':options.paddingTop})
                                    .text(options.items[i].class)
                               )
                               */
            }
        };

        return this.each(make);
    };
})(jQuery);

