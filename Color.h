#ifndef COLOR_H
#define COLOR_H

class Color
{
public :
	
	//Static default colors

	static const Color BLACK;
    static const Color WHITE;
    static const Color RED;
    static const Color GREEN;
    static const Color BLUE;
    static const Color CYAN;
    static const Color MAGENTA;
    static const Color YELLOW;

	/*****************
	**    METHODES
	******************/

	//Constructors & destructors
	//==========================

    Color();
    Color(Color const& source);
    Color(float r, float g, float b);
    explicit Color(float grey);

    virtual ~Color();

    //Assignement operators
    //=====================

    Color & operator = (Color const& source);
    Color & operator += (Color const& source);
    Color & operator += (float grey);
    Color & operator -= (Color const& source);
    Color & operator -= (float grey);
    Color & operator *= (Color const& source);
    Color & operator *= (float factor);
    Color & operator /= (float factor);

    //Comparison operators
    //====================

    friend bool operator == (Color const& lhs, Color const& rhs);
    friend bool operator != (Color const& lhs, Color const& rhs);

    //Operation operators
    //===================

    friend Color operator + (Color const& lhs, Color const& rhs);
    friend Color operator + (float lhs, Color const& rhs);
    friend Color operator + (Color const& lhs, float rhs);
    friend Color operator - (Color const& lhs, Color const& rhs);
    friend Color operator - (float lhs, Color const& rhs);
    friend Color operator - (Color const& lhs, float rhs);
    friend Color operator * (Color const& lhs, Color const& rhs);
    friend Color operator * (float lhs, Color const& rhs);
    friend Color operator * (Color const& lhs, float rhs);
    friend Color operator / (Color const& lhs, float rhs);

    //Setters and Getters
    //===================

    float getRed() const;
    void setRed(float r);
    float getGreen() const;
    void setGreen(float g);
    float getBlue() const;
    void setBlue(float b);
    void setRGB(float r, float g, float b);
    void setColor(Color const& color);
    float getGrey() const;
    void setGrey(float g);
    float getLuminosity() const;


private:

    /*****************
	**    ATTRIBUTS
	******************/

    float m_red;
    float m_green;
    float m_blue;

};

#endif
