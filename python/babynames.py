import sys
import re



def extract_names(filename):
  """
  Given a file name for baby.html, returns a list starting with the year string
  followed by the name-rank strings in alphabetical order.
  ['2006', 'Aaliyah 91', Aaron 57', 'Abagail 895', ' ...]
  """
  f=file(filename,'rU')
  text = f.read()

  year = re.search(r'Popularity\sin\s\d\d\d\d',text)
  if not year:
    print 'could not found year'
    sys.exit(1)
  #print year,";mfdla"
  names = re.findall(r'<td>(\d+)</td><td>(\w+)</td><td>(\w+)</td>',text)
  inter_list={}
  for name in names:
    ( rank, boyname, girlname)= name
    if boyname not in inter_list:
      inter_list[boyname]= rank
    if girlname not in inter_list:
      inter_list[girlname]=rank
  sorted_list=sorted(inter_list.keys())
  
  final_list=[]
  final_list.append(year)
  for x in sorted_list:
    final_list.append(x+" "+inter_list[x])
  return final_list


def main():
  # This command-line parsing code is provided.
  # Make a list of command line arguments, omitting the [0] element
  # which is the script itself.
  args = sys.argv[1:]
  #print 'siddhant' 
  if not args:
    print 'usage: [--summaryfile] file [file ...]'
    sys.exit(1)

  #print 'siddhant' 
  # Notice the summary flag and remove it from args if it is present.
  summary = False
  if args[0] == '--summaryfile':
    summary = True
    del args[0]
  #print 'siddhant' 
  #print args[0]

  #print 'siddhant' 
  for x in lists:
    #print 'siddhant' 
    print x
    if summary:
      f= open(filename,".summary",'w')
      f.write()
  lists = extract_names(args[0]) 
  # +++your code here+++
  # For each filename, get the names, then either print the text output
  # or write it to a summary file
  
if __name__ == '__main__':
  main()
