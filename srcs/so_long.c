/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:16:02 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/14 22:40:36 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. Parsing de la map
// utiliser la fonction get_next_line pour lire la map
// utiliser la fonction ft_split pour séparer les lignes de la map

*/

/* gestion des erreurs :
1. Regarder si l'extension de la carte est bien .ber (ft_strncmp)
2. Regarder si la carte est bien RECTANGULAIRE (même nombre de caractères par ligne)
3. Regarder si la carte est bien fermée par des murs (des 1)
4. Regarder si la carte contient bien au moins un joueur, une sortie et des collectibles
5. Regarder si la carte contient bien que des caractères autorisés (1, 0, P, C, E)/
les 1 (murs)
les 0 (sol)
les P (joueur)
les C (collectibles)
les E (sortie)
6. regarder si un joueur est bien présent sur la carte (1 SEUL joueur **sinon erreur**)
7. regarder si une sortie est bien présente sur la carte (1 SEULE sortie **sinon erreur**)
8. regarder si des collectibles sont bien présents sur la carte (au moins 1 **sinon erreur**)
9. regarder si le joueur est entourer de mur ppour afficher une erreur
10. regarder si la sortie est entourer de mur pour afficher une erreur
11. regarder si les collectibles sont entourer de mur pour afficher une erreur
12. faire attention a ce que le chemin soit accessible (pas de mur entre le joueur et la sortie)
*/

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;
	t_data	img;

	if (argc != 2)
		return (ft_error(ERROR));
	if (check_extension(argv[1]) == ERROR)
		return (ERROR);
	if (ft_parsing(argv[1], &map) == ERROR)
		return (ERROR);
	
	return (0);
}
