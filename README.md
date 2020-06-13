![Deploy](https://github.com/farukcan/farukcan.net/workflows/Deploy/badge.svg)
![GitHub pull requests](https://img.shields.io/github/issues-pr/farukcan/farukcan.net)
![Website](https://img.shields.io/website?label=farukcan.net&style=flat-square&url=https%3A%2F%2Fwww.farukcan.net)
![GitHub repo size](https://img.shields.io/github/repo-size/farukcan/farukcan.net?label=farukcan.net&style=flat-square)
![GitHub repo size](https://img.shields.io/github/repo-size/farukcan/farukcan.github.io?label=farukcan.github.io&style=flat-square)


# farukcan.net ![License](https://www.farukcan.net/images/cc-by-nc-sa.svg)

Hexo ile github-pages kullanılarak sitemi github üzerinde barındırmaktayım.
Buraya commitlenen herşey, github action ile otomatik deploy edilir.
github-pages reposu : https://github.com/farukcan/farukcan.github.io

## Siteyi klonlama
<pre>
git clone https://github.com/farukcan/farukcan.net farukcan.net
</pre>

## Hexo Kurulumu
<pre>
npm install hexo-cli -g
</pre>


## Editleme prosedürü
<pre>
git pull
npm install
hexo server -d
</pre>
[http://localhost:4000/admin](http://localhost:4000/admin)

## Yayınlama Prosedürü
<pre>
git status
git add .
git commit -m "farukcan.net reposuna mesaj"
git push origin master
# Alttakilere artık gerek yoktur, otomatik deploy edilir.
hexo clean
hexo deploy
</pre>
