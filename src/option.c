#include "../icl/icl.h"

bool    is_option(int ac, char **av)
{
        if (ac == 3) {
                if (ft_strcmp(av[1], "-a")) {
    //                    add_opt();
                        return true;
                }
                if (ft_strcmp(av[1], "-b") && is_num(av[2])) {
   //                     begin_opt();
                        return true;
                }
                if (ft_strcmp(av[1], "-c") && is_num(av[2])) {
  //                      check_opt();
                        return true;
                }
                if (ft_strcmp(av[1], "-d") && is_num(av[2])) {
 //                       del_opt();
                        return true;
                }
                return false;
        } else if (ac == 4) {
                if (ft_strcmp(av[1], "-e") && is_num(av[2])) {
//                        edit_opt();
                        return true;
                }
                return false;
        }
        return true;
}
