import os
import re
import sys
import urllib

"""Logpuzzle exercise
Given an apache logfile, find the puzzle urls and download the images.

Here's what a puzzle url looks like:
10.254.254.28 - - [06/Aug/2007:00:13:48 -0700] "GET /~foo/puzzle-bar-aaab.jpg HTTP/1.0" 302 528 "-" "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.6) Gecko/20070725 Firefox/2.0.0.6"
"""

def url_sort_key(url):
  
  match = re.search(r'-(\w+)-(\w+)\.\w+', url)
  if match:
    return match.group(2)
  else:
    return url

def read_urls(filename):
  hostname=filename[filename.index('_')+1:]
  print hostname
  dic ={}
  f = open(filename,'rU')
  for url in f:
    url1=re.search("GET\s(\S+)\s",url)

    
    if 'puzzle' in url1.group(1):
      dic['http://'+hostname+url1.group(1)]=1
  print dic
  return sorted(dic.keys(),key = url_sort_key)

def download_images(img_urls, dest_dir):
  
  if not os.path.exists(dest_dir):
    os.makedirs(dest_dir)
  i=0
  f = file(os.path.join(dest_dir, 'index.html'), 'w')
  f.write('<html><body>')
  print img_urls
  for x in img_urls:
    fil = "img%d.jpg" % i
    print 'Retrieving...', x
    urllib.urlretrieve(x,os.path.join(dest_dir,fil))
    i=i+1
    print "sidd"
    f.write('<img src= "%s">' % (fil,))
  f.write('</html></body>')  

def main():
  args = sys.argv[1:]

  if not args:
    print 'usage: [--todir dir] logfile '
    sys.exit(1)

  todir = ''
  if args[0] == '--todir':
    todir = args[1]
    del args[0:2]

  img_urls = read_urls(args[0])
  print img_urls
  if todir:
    download_images(img_urls, todir)
  else:
    print '\n'.join(img_urls)

if __name__ == '__main__':
  main()
