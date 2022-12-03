#ifndef MESSAGE_H
#define MESSAGE_H
#include <vector>
#include <string>
#include <iostream>

class message
{
private:
    static int _compteur;
    int _id;
    std::string _expediteur;
    std::vector<std::string> _destinataire;
public:
    virtual ~message() = default;
    message(std::string expediteur,std::vector<std::string> destinataire);
    int id() const;
    const std::string &expediteur() const;
    const std::vector<std::string> &destinataire() const;
    virtual void sortieflux(std::ostream & os) const = 0;
    bool contientDestinataire(const std::string &D);
};

#endif // MESSAGE_H
