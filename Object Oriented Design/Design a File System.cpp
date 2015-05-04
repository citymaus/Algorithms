/*
  Explain the data structures and algorithms that you would use to design an
  in-memory file system. Illustrate with an example in code where possible.
*/

#include <cstring>
#include <ctime>
#include <vector>

using namespace std;

class Entry {              // in Java, an abstract class
  protected:
    Directory parent;
    long created;
    long lastupdated;
    long lastAccessed;
    string name;
    bool isDirectory;

  public:
    Entry(string n, Directory p) 
    : name(n),
      parent(p),
      isDirectory(false)
    {
      time_t now = time(NULL);
      created = now;
      lastupdated = now;
      lastAccessed = now;
    }

    bool delete() 
    {
      if (parent == NULL) return false;
      return parent.deleteEntry(this);
    }

    virtual int size();       // in Java, abstract int size()

    string getFullPath() 
    {
      if (parent == NULL) return name;
      else 
        return parent.getFullPath() + "/" + name;
    }

    /* Getters and setters. */
    long getCreationTime() { return created; }
    long getLastUpdatedTime() { return lastupdated; }
    long getLastAccessedTime() { return lastAccessed; }
    void changeName(string n) { name = n; }
    string getName() { return name; }
    void setDirectory(bool d) { isDirectory = d; }
    bool isDirectory() { return isDirectory; }
};

class File : public Entry {         // in Java, File extends Entry
  private:
    string content;
    int size;

  public:
    File(String n, Directory p, int sz) 
    : size(sz)
    {
      super(n, p);
    }

    int size() { return size; }
    string getContents() { return content; }
    void setContents(string c) { content = c; }
};

class Directory : public Entry {    // in Java, File extends Entry
  protected:
    vector<Entry *> contents;

  public:
    Directory(string n, Directory p)
    {
      super(n, p);
      setDirectory(true);
    }

    int size() 
    {
      int size = 0;
      for (vector<int>::iterator it = contents.begin(); it != contents.end(); it++)
      {
        size += *it.size();
      }
      return size;
    }

    int numberOfFiles() 
    {
      int count = 0;
      for (vector<int>::iterator it = contents.begin(); it != contents.end(); it++)
      {
        if (*it.isDirectory()) 
        {
          count++; // Directory counts as a file
          Directory d = (Directory) *it;
          count += d.numberOfFiles();
        } 
        else if (! *it.isDirectory())   // File 
        {
          count++;
        }
      }
      return count;
    }

    bool deleteEntry(Entry *entry) 
    {
      bool erased = false;

      
      for (int i = 0; i < contents.size(); i++)
      { 
        if (strcmp(contents[i]->name, entry->name) == 0)
        {
          contents.erase(i);
          erased = true;
        }
      }

      return erased;
    }

    void addEntry(Entry *entry) 
    {
      contents->push_back(entry);
    }

  protected:
    vector<Entry *> getContents() { return contents; }
};