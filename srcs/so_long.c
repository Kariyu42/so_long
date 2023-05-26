/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:16:02 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/26 15:42:40 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* gestion des erreurs :
1. Regarder si l'extension de la carte est bien .ber (ft_strncmp) ✅
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
13. Regarder la width si elle est bien superieur a 3 et la height superieur a trois aussi
*/

#include "so_long.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		ft_putstr_fd(map->map[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

void	init_params(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->tools.door = 0;
	map->tools.player = 0;
	map->tools.collects = 0;
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_mlx	mlx;

	if (argc != 2)
		return (ft_error(2));
	if (check_extension(argv[1]) == ERROR)
		return (ft_error(3));
	collect_map(argv[1], &map);
	initialize_game(&map, &mlx);
	return (0);
}
