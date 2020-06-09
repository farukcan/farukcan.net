# farukcan.net

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
