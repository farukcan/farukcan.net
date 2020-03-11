# farukcan.net

Hexo ile github-pages kullanılarak sitemi github üzerinde barındırmaktayım.

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
hexo clean
hexo deploy
</pre>
