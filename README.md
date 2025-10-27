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

La fonctionnalité que je vais expliquer est celle liée à la lecture et à l'écriture dans les fichiers.
D'abord, la fonction appelée lors de la lecture ou de l'écriture appartient à la librairie fstream. Afin d'écrire dans un fichier, nous utilisons cette fonction selon le fichier.

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

Dans ce code, nous commençons par ouvrir le fichier en utilisant ofstream. Ofstream est un file stream qui se spécialise dans l'écriture dans un fichier. Après avoir ouvert le fichier, nous vérifions que celui-ci a effectivement été ouvert. Si ce n'est pas le cas, la fonction retourne une erreur. Dans le cas contraire, nous obtenons tous les livres en utilisant une fonction qui retourne chaque livre de la librairie. Ensuite, nous insérons les livres sous forme d'un string facilement lisible dans le fichier ouvert à la première étape en utilisant une méthode similaire à l'utilisation de cout. Après l'écriture, le fichier est fermé avec la fonction file.close() afin de libérer les ressources.
Pour la lecture, nous utilisons la fonction suivante.

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

Cette fonction utilise ifstream qui est le file stream se concentrant sur la lecture dans un fichier. Après avoir fait la même vérification que plus tôt, nous créons le string qui contiendra les lignes lues et une variable qui contiendra le nombre de lignes lues. Ensuite, nous utilisons la fonction getLine de la librairie fstream afin de lire le fichier ligne par ligne et nous stockons ces lignes dans le string créé précédemment. Il serait possible de simplement faire file >> line mais il lirait les mots, mot par mot, un à la fois. Ensuite, nous stockons les livres dans la librairie.

# Question 2

Personnellement, je commencerais par mettre les fichiers txt contenant les livres et les utilisateurs sur le cloud, afin de réduire les risques s'il y a une perte en termes d'équipement numérique. Ensuite, je remplacerais les fichiers txt par une base de données SQL. Ceci est possible si on utilise le mélange de l'API SQLAPI++ qui permet d'accéder et de manipuler les bases de données avec du code SQL. Oracle servirait de base de données mais ce n'est pas le seul choix possible. Une base de données permettrait une transition plus simple vers un site web éventuel et c'est un choix plus logique en termes de relation entre utilisateur et livre.
