# Construire le projet

Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:

```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de les copiers dans le repertoire `build` avec l'application `bibliotheque`

# Question 1 :

La fonctionalité que je vais expliquer est celle lié à la lecture et à l'écriture dans les fichiers.
D'abord la fonction appellé lors de la lecture ou de l'écriture appartient à la la librairie fstream. Afin d'écrire dans un fichier nous utilisant cette fonction selon le fichier.

```c++
bool FileManager::saveBooksToFile(Library& library) {
    ofstream file(booksFileName);
    if (!file.is_open()) {
        cout << "Erreur : Impossible d'ouvrir " << booksFileName << " en écriture.\n";
        return false;
    }

    auto books = library.getAllBooks();
    for (Book* book : books) {
        file << book->toFileFormat() << "\n";
    }

    file.close();
    return true;
}

```

Dans ce code nous commençant par ouvrir le fichier en utilisant ofstream. Ofstream est un file stream qui se spécifie dans la l'écriture dans un fichier. Après avoir ouvrit le fichier, nous vérifions que celui-ci à actuellement été ouvert. Si ce n'est pas le cas, la fonction retourne une erreur. Dans le cas contraire, nous obtenons tout les livres en utilisant une fonction qui retourne chaque livres de la librairie. Ensuite nous insérant les livres sous forme d'un string facilement lisible dans le fichier ouvert à la première étape en utilisant une méthode similaire à l'utilisation de cout. Après la lecture, le fichier est fermer avec la fonction file.close() afin de libérer les ressources.
Pour La lecture, nous utilisant la fonction suivante.

```c++
bool FileManager::loadBooksFromFile(Library& library) {
    ifstream file(booksFileName);
    if (!file.is_open()) {
        cout << "Aucun fichier de livres existant trouvé. Démarrage avec une bibliothèque vide.\n";
        return false;
    }

    string line;
    int count = 0;
    while (getline(file, line)) {
        if (!line.empty()) {
            Book book;
            book.fromFileFormat(line);
            library.addBook(book);
            count++;
        }
    }

    file.close();
    cout << "Chargé " << count << " livre(s) depuis le fichier.\n";
    return true;
}

```

Cette fonction utilise ifstream qui est le file stream se concentrant sur l'écriture dans un fichier. Après avoir fait la même vérification que plus tôt, nous créans le string qui contiendra les lignes lues et une variables qui contiendra le nombre de ligne lue. Ensuite, nous utilisant la fonction getLine de la librairie fstream afin de lire le fichier ligne par ligne et nous stockant ces lignes dans le string créé précedemment. Il serait possible de simplement faire file >> line mais il lirait les mot, mot par mots, un à la fois. Ensuite, nous stockants les livres dans la librairie.

# Question 2
