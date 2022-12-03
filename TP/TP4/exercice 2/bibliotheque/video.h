#ifndef VIDEO_H
#define VIDEO_H
#include "document.h"

enum class support{
    DVD, BluRay, BluRay3D
};

class video : public document
{
private:
    support typeSupport;
public:
    video(support typeSupport, const std::string &nomAuteur, const std::string &titre);

    // document interface
public:
    float cout() const override;
    bool empruntable() const override;
    std::string type() const override;
    void sortie(std::ostream &os) const override;
    document *clone() const override;
    support getTypeSupport() const;
};

#endif // VIDEO_H
