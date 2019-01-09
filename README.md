<h1 align="center">
ft_ls 
</h1>

<h3 align="center"><b>Description</b></h3>
<p>Pour tout connaitre du filesystem, de la façon dont sont rangés les fichiers et répertoires, codez par vous-même une des commandes les plus utilisées : ls.</p>

<p><b>Objectif :</b> Reproduire la commande ls.</p>
<p><b>Langage :</b> C.</p>
<p><b>Fonctions autorisées :</b> write, opendir, readdir, closedir, stat, lstat, getpwuid, getgrgid, listxattr, getxattr, time, ctime, readlink, malloc, free, perror, strerror, exit + d'autres dans le cadre des bonus</p>

<h3 align="center">Fonctionalité</h3>
<p><b>Arguments :</b> Fichiers, Dossiers et options</p>
<p><b>Options obligatoires:</b> R, a, l, r et t</p>
<p><b>Options bonus :</b> 1, A, C, S, c, d, f, g, i, k, m, n, p, s et u</p>
<p><b>Autres Bonus : </b>Couleurs (Dossiers, Liens Symboliques, Executables), Gestions des attributs etendus, un affichage très correcte</p>

<h3 align="center"> Documentation </h3>
<a href=https://linux.die.net/man/2/stat>stat</a></br>
<a href=https://linux.die.net/man/2/lstat>lstat</a></br>
<a href=https://stackoverflow.com/questions/36229265/how-to-get-extended-attributes-of-a-fileunix-c> Handle ACL</a></br>
<a href=https://unix.stackexchange.com/questions/103114/what-do-the-fields-in-ls-al-output-mean>What does ls -l shows</a></br>
<a href=https://linux.die.net/man/2/stat>stat</a></br>



Ways to improve mem : use bit to bit instead of int array for options ||| don't save stat and lstat in struct </br>
Ways to improve speed : don't browse twice list (one for getting len and other one to print)
