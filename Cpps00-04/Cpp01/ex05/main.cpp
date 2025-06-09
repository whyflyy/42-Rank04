/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:15:34 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/09 16:56:01 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl    Chato;
    
    Chato.complain("DEBUG");
    Chato.complain("INFO");
    Chato.complain("WARNING");
    Chato.complain("ERROR");
    Chato.complain("NOTHING");
    return (0);
}
