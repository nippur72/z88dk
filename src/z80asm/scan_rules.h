











static const int lexer_start = 21;
static const int lexer_error = 0;

static const int lexer_en_main = 21;




static void set_scan_buf( char *text, Bool _at_bol )
{
    Str_set( input_buf, text );


    at_bol = _at_bol;
    pe = input_buf->str + input_buf->len;
    eof = pe;



    {
        cs = lexer_start;
        ts = 0;
        te = 0;
        act = 0;
    }


}

static tokid_t _scan_get( void )
{


    {
        short _widec;

        if ( p == pe )
            goto _test_eof;

        switch ( cs )
        {
tr0:

            {
                {
                    p = ( ( te ) ) - 1;
                }
                {
                    sym.tok = TK_LPAREN;
                    sym.text = "(";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr9:

            {
                te = p + 1;
                {
                    sym.tok = TK_IND_BC;
                    sym.text = "(BC)";
                    sym.cpu_ind_reg16 = IND_REG16_BC;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr10:

            {
                te = p + 1;
                {
                    sym.tok = TK_IND_C;
                    sym.text = "(C)";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr12:

            {
                te = p + 1;
                {
                    sym.tok = TK_IND_DE;
                    sym.text = "(DE)";
                    sym.cpu_ind_reg16 = IND_REG16_DE;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr14:

            {
                te = p + 1;
                {
                    sym.tok = TK_IND_HL;
                    sym.text = "(HL)";
                    sym.cpu_ind_reg16 = IND_REG16_HL;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr17:

            {
                te = p + 1;
                {
                    sym.tok = TK_IND_IX;
                    sym.text = "(IX";
                    p--;
                    te--;
                    sym.cpu_ind_reg16 = IND_REG16_HL;
                    sym.cpu_idx_reg = opts.swap_ix_iy ? IDX_REG_IY : IDX_REG_IX;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr18:

            {
                te = p + 1;
                {
                    sym.tok = TK_IND_IY;
                    sym.text = "(IY";
                    p--;
                    te--;
                    sym.cpu_ind_reg16 = IND_REG16_HL;
                    sym.cpu_idx_reg = opts.swap_ix_iy ? IDX_REG_IX : IDX_REG_IY;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr20:

            {
                te = p + 1;
                {
                    sym.tok = TK_IND_SP;
                    sym.text = "(SP)";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr21:

            {
                switch ( act )
                {
                case 1:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_ASMPC;
                    sym.text = "ASMPC";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 37:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_NZ;
                    sym.text = "NZ";
                    sym.cpu_flag = FLAG_NZ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 38:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_Z;
                    sym.text = "Z";
                    sym.cpu_flag = FLAG_Z;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 39:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_NC;
                    sym.text = "NC";
                    sym.cpu_flag = FLAG_NC;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 40:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_C;
                    sym.text = "C";
                    sym.cpu_flag = FLAG_C;
                    sym.cpu_reg8 = REG8_C;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 41:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_PO;
                    sym.text = "PO";
                    sym.cpu_flag = FLAG_PO;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 42:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_PE;
                    sym.text = "PE";
                    sym.cpu_flag = FLAG_PE;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 43:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_P;
                    sym.text = "P";
                    sym.cpu_flag = FLAG_P;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 44:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_M;
                    sym.text = "M";
                    sym.cpu_flag = FLAG_M;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 45:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_B;
                    sym.text = "B";
                    sym.cpu_reg8 = REG8_B;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 46:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_D;
                    sym.text = "D";
                    sym.cpu_reg8 = REG8_D;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 47:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_E;
                    sym.text = "E";
                    sym.cpu_reg8 = REG8_E;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 48:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_H;
                    sym.text = "H";
                    sym.cpu_reg8 = REG8_H;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 49:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_IXH;
                    sym.text = "IXH";
                    sym.cpu_reg8 = REG8_H;
                    sym.cpu_idx_reg = opts.swap_ix_iy ? IDX_REG_IY : IDX_REG_IX;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 50:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_IYH;
                    sym.text = "IYH";
                    sym.cpu_reg8 = REG8_H;
                    sym.cpu_idx_reg = opts.swap_ix_iy ? IDX_REG_IX : IDX_REG_IY;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 51:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_L;
                    sym.text = "L";
                    sym.cpu_reg8 = REG8_L;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 52:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_IXL;
                    sym.text = "IXL";
                    sym.cpu_reg8 = REG8_L;
                    sym.cpu_idx_reg = opts.swap_ix_iy ? IDX_REG_IY : IDX_REG_IX;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 53:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_IYL;
                    sym.text = "IYL";
                    sym.cpu_reg8 = REG8_L;
                    sym.cpu_idx_reg = opts.swap_ix_iy ? IDX_REG_IX : IDX_REG_IY;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 54:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_A;
                    sym.text = "A";
                    sym.cpu_reg8 = REG8_A;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 55:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_F;
                    sym.text = "F";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 56:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_I;
                    sym.text = "I";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 57:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_IIR;
                    sym.text = "IIR";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 58:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_R;
                    sym.text = "R";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 59:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_EIR;
                    sym.text = "EIR";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 61:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_BC;
                    sym.text = "BC";
                    sym.cpu_reg16_af = sym.cpu_reg16_sp = REG16_BC;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 62:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_DE;
                    sym.text = "DE";
                    sym.cpu_reg16_af = sym.cpu_reg16_sp = REG16_DE;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 63:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_HL;
                    sym.text = "HL";
                    sym.cpu_reg16_af = sym.cpu_reg16_sp = REG16_HL;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 64:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_IX;
                    sym.text = "IX";
                    sym.cpu_reg16_af = sym.cpu_reg16_sp = REG16_HL;
                    sym.cpu_idx_reg = opts.swap_ix_iy ? IDX_REG_IY : IDX_REG_IX;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 65:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_IY;
                    sym.text = "IY";
                    sym.cpu_reg16_af = sym.cpu_reg16_sp = REG16_HL;
                    sym.cpu_idx_reg = opts.swap_ix_iy ? IDX_REG_IX : IDX_REG_IY;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 66:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_AF;
                    sym.text = "AF";
                    sym.cpu_reg16_af = REG16_AF;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 67:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_SP;
                    sym.text = "SP";
                    sym.cpu_reg16_sp = REG16_SP;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 79:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_EXX;
                    sym.text = "EXX";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 80:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_HALT;
                    sym.text = "HALT";

                    if ( opts.cpu & CPU_RABBIT )
                    {
                        error_illegal_ident();
                    };

                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 81:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_IM;
                    sym.text = "IM";

                    if ( opts.cpu & CPU_RABBIT )
                    {
                        error_illegal_ident();
                    };

                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 82:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_NOP;
                    sym.text = "NOP";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 85:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_NAME;
                    set_tok_name();
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 87:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }




                    sym.tok = TK_NUMBER;
                    sym.number = scan_num( ts, te - ts, 10 );
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 89:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_NUMBER;
                    sym.number = scan_num( ts + 1, te - ts - 1, 16 );
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 91:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_NUMBER;
                    sym.number = scan_num( ts, te - ts - 1, 2 );
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 93:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_NUMBER;
                    sym.number = scan_num( ts + 2, te - ts - 2, 2 );
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;

                case 97:
                {
                    {
                        p = ( ( te ) ) - 1;
                    }
                    sym.tok = TK_NIL;
                    skip_to_newline();
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
                break;
                }
            }
            goto st21;
tr23:

            {
                te = p + 1;
                {
                    sym.tok = TK_NUMBER;
                    sym.number = scan_num( ts, te - ts - 1, 16 );
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr24:

            {
                {
                    p = ( ( te ) ) - 1;
                }
                {




                    sym.tok = TK_NUMBER;
                    sym.number = scan_num( ts, te - ts, 10 );
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr26:

            {
                {
                    p = ( ( te ) ) - 1;
                }
                {
                    sym.tok = TK_NIL;
                    skip_to_newline();
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr28:

            {
                te = p + 1;
                {
                    sym.tok = TK_NUMBER;
                    sym.number = scan_num( ts + 2, te - ts - 3, 2 );
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr29:

            {
                {
                    p = ( ( te ) ) - 1;
                }
                {
                    sym.tok = TK_NAME;
                    set_tok_name();
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr30:

            {
                te = p + 1;
                {
                    sym.tok = TK_DS_B;
                    sym.text = "DS.B";
                    sym.ds_size = 1;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr31:

            {
                te = p + 1;
                {
                    sym.tok = TK_DS_L;
                    sym.text = "DS.L";
                    sym.ds_size = 4;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr32:

            {
                te = p + 1;
                {
                    sym.tok = TK_DS_P;
                    sym.text = "DS.P";
                    sym.ds_size = 3;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr33:

            {
                te = p + 1;
                {
                    sym.tok = TK_DS_W;
                    sym.text = "DS.W";
                    sym.ds_size = 2;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr34:

            {
                {
                    p = ( ( te ) ) - 1;
                }
                {
                    sym.tok = TK_DOT;
                    sym.text = ".";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr38:

            {
                te = p + 1;
                {

                    while ( ts[ 0] == '.' || isspace( ts[ 0] ) ) ts++;

                    while ( te[-1] == ':' || isspace( te[-1] ) ) te--;


                    sym.tok = TK_LABEL;
                    set_tok_name();
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr39:

            {
                te = p + 1;
            }
            goto st21;
tr40:

            {
                te = p + 1;
                {
                    sym.tok = TK_NEWLINE;
                    sym.text = "\n";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr42:

            {
                te = p + 1;
                {
                    sym.tok = TK_STRING;

                    if ( ! get_sym_string() )
                    {
                        error_unclosed_string();
                    }

                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr43:

            {
                te = p + 1;
                {
                    sym.tok = TK_CONST_EXPR;
                    sym.text = "#";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr45:

            {
                te = p + 1;
                {
                    sym.tok = TK_MOD;
                    sym.text = "%";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr47:

            {
                te = p + 1;
                {
                    sym.tok = TK_NUMBER;

                    if ( get_sym_string() &&
                            sym_string->len == 1 )
                    {
                        sym.number = sym_string->str[0];
                    }
                    else
                    {
                        sym.number = 0;
                        error_invalid_squoted_string();
                    }

                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr49:

            {
                te = p + 1;
                {
                    sym.tok = TK_RPAREN;
                    sym.text = ")";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr51:

            {
                te = p + 1;
                {
                    sym.tok = TK_PLUS;
                    sym.text = "+";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr52:

            {
                te = p + 1;
                {
                    sym.tok = TK_COMMA;
                    sym.text = ",";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr53:

            {
                te = p + 1;
                {
                    sym.tok = TK_MINUS;
                    sym.text = "-";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr54:

            {
                te = p + 1;
                {
                    sym.tok = TK_DIVIDE;
                    sym.text = "/";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr59:

            {
                te = p + 1;
                {
                    sym.tok = TK_COLON;
                    sym.text = ":";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr64:

            {
                te = p + 1;
                {
                    sym.tok = TK_QUESTION;
                    sym.text = "?";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr66:

            {
                te = p + 1;
                {
                    sym.tok = TK_LSQUARE;
                    sym.text = "[";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr67:

            {
                te = p + 1;
                {
                    sym.tok = TK_NIL;
                    skip_to_newline();
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr68:

            {
                te = p + 1;
                {
                    sym.tok = TK_RSQUARE;
                    sym.text = "]";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr69:

            {
                te = p + 1;
                {
                    sym.tok = TK_BIN_XOR;
                    sym.text = "^";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr70:

            {
                te = p + 1;
                {
                    sym.tok = TK_LCURLY;
                    sym.text = "{";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr72:

            {
                te = p + 1;
                {
                    sym.tok = TK_RCURLY;
                    sym.text = "}";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr73:

            {
                te = p + 1;
                {
                    sym.tok = TK_BIN_NOT;
                    sym.text = "~";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr74:

            {
                te = p + 1;
                {
                    sym.tok = TK_DOT;
                    sym.text = ".";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr108:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_LOG_NOT;
                    sym.text = "!";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr109:

            {
                te = p + 1;
                {
                    sym.tok = TK_NOT_EQ;
                    sym.text = "!=";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr111:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_BIN_AND;
                    sym.text = "&";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr112:

            {
                te = p + 1;
                {
                    sym.tok = TK_LOG_AND;
                    sym.text = "&&";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr113:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_LPAREN;
                    sym.text = "(";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr114:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_MULTIPLY;
                    sym.text = "*";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr115:

            {
                te = p + 1;
                {
                    sym.tok = TK_POWER;
                    sym.text = "**";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr116:

            {
                te = p;
                p--;
                {




                    sym.tok = TK_NUMBER;
                    sym.number = scan_num( ts, te - ts, 10 );
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr120:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_NUMBER;
                    sym.number = scan_num( ts, te - ts - 1, 2 );
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr122:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_NUMBER;
                    sym.number = scan_num( ts + 2, te - ts - 2, 16 );
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr123:

            {
                te = p;
                p--;
            }
            goto st21;
tr124:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_LESS;
                    sym.text = "<";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr125:

            {
                te = p + 1;
                {
                    sym.tok = TK_LEFT_SHIFT;
                    sym.text = "<<";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr126:

            {
                te = p + 1;
                {
                    sym.tok = TK_LESS_EQ;
                    sym.text = "<=";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr127:

            {
                te = p + 1;
                {
                    sym.tok = TK_NOT_EQ;
                    sym.text = "<>";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr128:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_EQUAL;
                    sym.text = "=";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr129:

            {
                te = p + 1;
                {
                    sym.tok = TK_EQUAL;
                    sym.text = "==";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr130:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_GREATER;
                    sym.text = ">";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr131:

            {
                te = p + 1;
                {
                    sym.tok = TK_GREATER_EQ;
                    sym.text = ">=";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr132:

            {
                te = p + 1;
                {
                    sym.tok = TK_RIGHT_SHIFT;
                    sym.text = ">>";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr133:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_NIL;
                    skip_to_newline();
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr136:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_NUMBER;
                    sym.number = scan_num( ts + 1, te - ts - 1, 2 );
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr137:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_BIN_OR;
                    sym.text = "|";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr138:

            {
                te = p + 1;
                {
                    sym.tok = TK_LOG_OR;
                    sym.text = "||";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr139:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_A;
                    sym.text = "A";
                    sym.cpu_reg8 = REG8_A;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr142:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_AF;
                    sym.text = "AF";
                    sym.cpu_reg16_af = REG16_AF;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr143:

            {
                te = p + 1;
                {
                    sym.tok = TK_AF1;
                    sym.text = "AF'";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr144:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_NAME;
                    set_tok_name();
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr148:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_B;
                    sym.text = "B";
                    sym.cpu_reg8 = REG8_B;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr150:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_D;
                    sym.text = "D";
                    sym.cpu_reg8 = REG8_D;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr154:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_E;
                    sym.text = "E";
                    sym.cpu_reg8 = REG8_E;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr159:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_H;
                    sym.text = "H";
                    sym.cpu_reg8 = REG8_H;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr164:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_I;
                    sym.text = "I";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr170:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_IX;
                    sym.text = "IX";
                    sym.cpu_reg16_af = sym.cpu_reg16_sp = REG16_HL;
                    sym.cpu_idx_reg = opts.swap_ix_iy ? IDX_REG_IY : IDX_REG_IX;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr173:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_IY;
                    sym.text = "IY";
                    sym.cpu_reg16_af = sym.cpu_reg16_sp = REG16_HL;
                    sym.cpu_idx_reg = opts.swap_ix_iy ? IDX_REG_IX : IDX_REG_IY;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr180:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_P;
                    sym.text = "P";
                    sym.cpu_flag = FLAG_P;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr184:

            {
                te = p;
                p--;
                {
                    sym.tok = TK_DOT;
                    sym.text = ".";
                    ;
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
tr185:

            {
                te = p;
                p--;
                {

                    while ( ts[ 0] == '.' || isspace( ts[ 0] ) ) ts++;

                    while ( te[-1] == ':' || isspace( te[-1] ) ) te--;


                    sym.tok = TK_LABEL;
                    set_tok_name();
                    {
                        p++;
                        cs = 21;
                        goto _out;
                    }
                }
            }
            goto st21;
st21:

            {
                ts = 0;
            }

            if ( ++p == pe )
                goto _test_eof21;

        case 21:

        {
            ts = p;
        }

        _widec = ( *p );

        if ( ( *p ) < 65 )
        {
            if ( 46 <= ( *p ) && ( *p ) <= 46 )
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }
        }
        else if ( ( *p ) > 90 )
        {
            if ( ( *p ) > 95 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) >= 95 )
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }
        }
        else
        {
            _widec = ( short )( 128 + ( ( *p ) - -128 ) );

            if (

                at_bol ) _widec += 256;
        }

        switch ( _widec )
        {
        case 10:
            goto tr40;

        case 33:
            goto st22;

        case 34:
            goto tr42;

        case 35:
            goto tr43;

        case 36:
            goto tr44;

        case 37:
            goto tr45;

        case 38:
            goto st24;

        case 39:
            goto tr47;

        case 40:
            goto tr48;

        case 41:
            goto tr49;

        case 42:
            goto st26;

        case 43:
            goto tr51;

        case 44:
            goto tr52;

        case 45:
            goto tr53;

        case 47:
            goto tr54;

        case 48:
            goto tr56;

        case 49:
            goto tr57;

        case 58:
            goto tr59;

        case 59:
            goto st33;

        case 60:
            goto st34;

        case 61:
            goto st35;

        case 62:
            goto st36;

        case 63:
            goto tr64;

        case 64:
            goto tr65;

        case 91:
            goto tr66;

        case 92:
            goto tr67;

        case 93:
            goto tr68;

        case 94:
            goto tr69;

        case 96:
            goto tr67;

        case 123:
            goto tr70;

        case 124:
            goto st39;

        case 125:
            goto tr72;

        case 126:
            goto tr73;

        case 127:
            goto tr39;

        case 302:
            goto tr74;

        case 321:
            goto st40;

        case 322:
            goto st46;

        case 323:
            goto tr77;

        case 324:
            goto st47;

        case 325:
            goto st49;

        case 326:
            goto tr80;

        case 328:
            goto st52;

        case 329:
            goto st55;

        case 332:
            goto tr84;

        case 333:
            goto tr85;

        case 334:
            goto st59;

        case 336:
            goto st61;

        case 338:
            goto tr88;

        case 339:
            goto st62;

        case 346:
            goto tr90;

        case 351:
            goto tr81;

        case 353:
            goto st40;

        case 354:
            goto st46;

        case 355:
            goto tr77;

        case 356:
            goto st47;

        case 357:
            goto st49;

        case 358:
            goto tr80;

        case 360:
            goto st52;

        case 361:
            goto st55;

        case 364:
            goto tr84;

        case 365:
            goto tr85;

        case 366:
            goto st59;

        case 368:
            goto st61;

        case 370:
            goto tr88;

        case 371:
            goto st62;

        case 378:
            goto tr90;

        case 558:
            goto tr91;

        case 577:
            goto tr92;

        case 578:
            goto tr93;

        case 579:
            goto tr94;

        case 580:
            goto tr95;

        case 581:
            goto tr96;

        case 582:
            goto tr97;

        case 584:
            goto tr99;

        case 585:
            goto tr100;

        case 588:
            goto tr101;

        case 589:
            goto tr102;

        case 590:
            goto tr103;

        case 592:
            goto tr104;

        case 594:
            goto tr105;

        case 595:
            goto tr106;

        case 602:
            goto tr107;

        case 607:
            goto tr98;

        case 609:
            goto tr92;

        case 610:
            goto tr93;

        case 611:
            goto tr94;

        case 612:
            goto tr95;

        case 613:
            goto tr96;

        case 614:
            goto tr97;

        case 616:
            goto tr99;

        case 617:
            goto tr100;

        case 620:
            goto tr101;

        case 621:
            goto tr102;

        case 622:
            goto tr103;

        case 624:
            goto tr104;

        case 626:
            goto tr105;

        case 627:
            goto tr106;

        case 634:
            goto tr107;
        }

        if ( _widec < 327 )
        {
            if ( _widec > 32 )
            {
                if ( 50 <= _widec && _widec <= 57 )
                    goto tr58;
            }
            else
                goto tr39;
        }
        else if ( _widec > 345 )
        {
            if ( _widec < 583 )
            {
                if ( 359 <= _widec && _widec <= 377 )
                    goto tr81;
            }
            else if ( _widec > 601 )
            {
                if ( 615 <= _widec && _widec <= 633 )
                    goto tr98;
            }
            else
                goto tr98;
        }
        else
            goto tr81;

        goto st0;
st22:

        if ( ++p == pe )
            goto _test_eof22;

        case 22:
            if ( ( *p ) == 61 )
                goto tr109;

            goto tr108;
tr44:

            {
                te = p + 1;
            }

            {
                act = 97;
            }
            goto st23;
tr110:

            {
                te = p + 1;
            }

            {
                act = 89;
            }
            goto st23;
st23:

            if ( ++p == pe )
                goto _test_eof23;

        case 23:

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr110;
            }
            else if ( ( *p ) > 70 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 102 )
                    goto tr110;
            }
            else
                goto tr110;

            goto tr21;
st24:

            if ( ++p == pe )
                goto _test_eof24;

        case 24:
            if ( ( *p ) == 38 )
                goto tr112;

            goto tr111;
tr48:

            {
                te = p + 1;
            }
            goto st25;
st25:

            if ( ++p == pe )
                goto _test_eof25;

        case 25:

            switch ( ( *p ) )
            {
            case 9:
                goto st1;

            case 32:
                goto st1;

            case 66:
                goto st2;

            case 67:
                goto st4;

            case 68:
                goto st5;

            case 72:
                goto st7;

            case 73:
                goto st9;

            case 83:
                goto st12;

            case 98:
                goto st2;

            case 99:
                goto st4;

            case 100:
                goto st5;

            case 104:
                goto st7;

            case 105:
                goto st9;

            case 115:
                goto st12;
            }

            goto tr113;
st1:

            if ( ++p == pe )
                goto _test_eof1;

        case 1:
            switch ( ( *p ) )
            {
            case 9:
                goto st1;

            case 32:
                goto st1;

            case 66:
                goto st2;

            case 67:
                goto st4;

            case 68:
                goto st5;

            case 72:
                goto st7;

            case 73:
                goto st9;

            case 83:
                goto st12;

            case 98:
                goto st2;

            case 99:
                goto st4;

            case 100:
                goto st5;

            case 104:
                goto st7;

            case 105:
                goto st9;

            case 115:
                goto st12;
            }

            goto tr0;
st2:

            if ( ++p == pe )
                goto _test_eof2;

        case 2:
            switch ( ( *p ) )
            {
            case 67:
                goto st3;

            case 99:
                goto st3;
            }

            goto tr0;
st3:

            if ( ++p == pe )
                goto _test_eof3;

        case 3:
            switch ( ( *p ) )
            {
            case 9:
                goto st3;

            case 32:
                goto st3;

            case 41:
                goto tr9;
            }

            goto tr0;
st4:

            if ( ++p == pe )
                goto _test_eof4;

        case 4:
            switch ( ( *p ) )
            {
            case 9:
                goto st4;

            case 32:
                goto st4;

            case 41:
                goto tr10;
            }

            goto tr0;
st5:

            if ( ++p == pe )
                goto _test_eof5;

        case 5:
            switch ( ( *p ) )
            {
            case 69:
                goto st6;

            case 101:
                goto st6;
            }

            goto tr0;
st6:

            if ( ++p == pe )
                goto _test_eof6;

        case 6:
            switch ( ( *p ) )
            {
            case 9:
                goto st6;

            case 32:
                goto st6;

            case 41:
                goto tr12;
            }

            goto tr0;
st7:

            if ( ++p == pe )
                goto _test_eof7;

        case 7:
            switch ( ( *p ) )
            {
            case 76:
                goto st8;

            case 108:
                goto st8;
            }

            goto tr0;
st8:

            if ( ++p == pe )
                goto _test_eof8;

        case 8:
            switch ( ( *p ) )
            {
            case 9:
                goto st8;

            case 32:
                goto st8;

            case 41:
                goto tr14;
            }

            goto tr0;
st9:

            if ( ++p == pe )
                goto _test_eof9;

        case 9:
            switch ( ( *p ) )
            {
            case 88:
                goto st10;

            case 89:
                goto st11;

            case 120:
                goto st10;

            case 121:
                goto st11;
            }

            goto tr0;
st10:

            if ( ++p == pe )
                goto _test_eof10;

        case 10:
            switch ( ( *p ) )
            {
            case 9:
                goto st10;

            case 32:
                goto st10;

            case 41:
                goto tr17;

            case 43:
                goto tr17;

            case 45:
                goto tr17;
            }

            goto tr0;
st11:

            if ( ++p == pe )
                goto _test_eof11;

        case 11:
            switch ( ( *p ) )
            {
            case 9:
                goto st11;

            case 32:
                goto st11;

            case 41:
                goto tr18;

            case 43:
                goto tr18;

            case 45:
                goto tr18;
            }

            goto tr0;
st12:

            if ( ++p == pe )
                goto _test_eof12;

        case 12:
            switch ( ( *p ) )
            {
            case 80:
                goto st13;

            case 112:
                goto st13;
            }

            goto tr0;
st13:

            if ( ++p == pe )
                goto _test_eof13;

        case 13:
            switch ( ( *p ) )
            {
            case 9:
                goto st13;

            case 32:
                goto st13;

            case 41:
                goto tr20;
            }

            goto tr0;
st26:

            if ( ++p == pe )
                goto _test_eof26;

        case 26:
            if ( ( *p ) == 42 )
                goto tr115;

            goto tr114;
st0:
            cs = 0;
            goto _out;
tr56:

            {
                te = p + 1;
            }

            {
                act = 87;
            }
            goto st27;
st27:

            if ( ++p == pe )
                goto _test_eof27;

        case 27:

            switch ( ( *p ) )
            {
            case 66:
                goto tr117;

            case 72:
                goto tr23;

            case 88:
                goto st15;

            case 98:
                goto tr117;

            case 104:
                goto tr23;

            case 120:
                goto st15;
            }

            if ( ( *p ) < 50 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 49 )
                    goto tr57;
            }
            else if ( ( *p ) > 57 )
            {
                if ( ( *p ) > 70 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 102 )
                        goto st14;
                }
                else if ( ( *p ) >= 65 )
                    goto st14;
            }
            else
                goto tr58;

            goto tr116;
tr57:

            {
                te = p + 1;
            }

            {
                act = 87;
            }
            goto st28;
st28:

            if ( ++p == pe )
                goto _test_eof28;

        case 28:

            switch ( ( *p ) )
            {
            case 66:
                goto tr119;

            case 72:
                goto tr23;

            case 98:
                goto tr119;

            case 104:
                goto tr23;
            }

            if ( ( *p ) < 50 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 49 )
                    goto tr57;
            }
            else if ( ( *p ) > 57 )
            {
                if ( ( *p ) > 70 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 102 )
                        goto st14;
                }
                else if ( ( *p ) >= 65 )
                    goto st14;
            }
            else
                goto tr58;

            goto tr116;
tr58:

            {
                te = p + 1;
            }

            {
                act = 87;
            }
            goto st29;
st29:

            if ( ++p == pe )
                goto _test_eof29;

        case 29:

            switch ( ( *p ) )
            {
            case 72:
                goto tr23;

            case 104:
                goto tr23;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr58;
            }
            else if ( ( *p ) > 70 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 102 )
                    goto st14;
            }
            else
                goto st14;

            goto tr116;
st14:

            if ( ++p == pe )
                goto _test_eof14;

        case 14:
            switch ( ( *p ) )
            {
            case 72:
                goto tr23;

            case 104:
                goto tr23;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto st14;
            }
            else if ( ( *p ) > 70 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 102 )
                    goto st14;
            }
            else
                goto st14;

            goto tr21;
tr119:

            {
                te = p + 1;
            }

            {
                act = 91;
            }
            goto st30;
st30:

            if ( ++p == pe )
                goto _test_eof30;

        case 30:

            switch ( ( *p ) )
            {
            case 72:
                goto tr23;

            case 104:
                goto tr23;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto st14;
            }
            else if ( ( *p ) > 70 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 102 )
                    goto st14;
            }
            else
                goto st14;

            goto tr120;
tr117:

            {
                te = p + 1;
            }

            {
                act = 91;
            }
            goto st31;
tr121:

            {
                te = p + 1;
            }

            {
                act = 93;
            }
            goto st31;
st31:

            if ( ++p == pe )
                goto _test_eof31;

        case 31:

            switch ( ( *p ) )
            {
            case 72:
                goto tr23;

            case 104:
                goto tr23;
            }

            if ( ( *p ) < 50 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 49 )
                    goto tr121;
            }
            else if ( ( *p ) > 57 )
            {
                if ( ( *p ) > 70 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 102 )
                        goto st14;
                }
                else if ( ( *p ) >= 65 )
                    goto st14;
            }
            else
                goto st14;

            goto tr21;
st15:

            if ( ++p == pe )
                goto _test_eof15;

        case 15:
            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto st32;
            }
            else if ( ( *p ) > 70 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 102 )
                    goto st32;
            }
            else
                goto st32;

            goto tr24;
st32:

            if ( ++p == pe )
                goto _test_eof32;

        case 32:
            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto st32;
            }
            else if ( ( *p ) > 70 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 102 )
                    goto st32;
            }
            else
                goto st32;

            goto tr122;
st33:

            if ( ++p == pe )
                goto _test_eof33;

        case 33:
            if ( ( *p ) == 10 )
                goto tr123;

            goto st33;
st34:

            if ( ++p == pe )
                goto _test_eof34;

        case 34:
            switch ( ( *p ) )
            {
            case 60:
                goto tr125;

            case 61:
                goto tr126;

            case 62:
                goto tr127;
            }

            goto tr124;
st35:

            if ( ++p == pe )
                goto _test_eof35;

        case 35:
            if ( ( *p ) == 61 )
                goto tr129;

            goto tr128;
st36:

            if ( ++p == pe )
                goto _test_eof36;

        case 36:
            switch ( ( *p ) )
            {
            case 61:
                goto tr131;

            case 62:
                goto tr132;
            }

            goto tr130;
tr65:

            {
                te = p + 1;
            }
            goto st37;
st37:

            if ( ++p == pe )
                goto _test_eof37;

        case 37:

            if ( ( *p ) == 34 )
                goto st16;

            if ( 48 <= ( *p ) && ( *p ) <= 49 )
                goto st38;

            goto tr133;
st16:

            if ( ++p == pe )
                goto _test_eof16;

        case 16:
            switch ( ( *p ) )
            {
            case 35:
                goto st17;

            case 45:
                goto st17;
            }

            goto tr26;
st17:

            if ( ++p == pe )
                goto _test_eof17;

        case 17:
            switch ( ( *p ) )
            {
            case 34:
                goto tr28;

            case 35:
                goto st17;

            case 45:
                goto st17;
            }

            goto tr26;
st38:

            if ( ++p == pe )
                goto _test_eof38;

        case 38:
            if ( 48 <= ( *p ) && ( *p ) <= 49 )
                goto st38;

            goto tr136;
st39:

            if ( ++p == pe )
                goto _test_eof39;

        case 39:
            if ( ( *p ) == 124 )
                goto tr138;

            goto tr137;
st40:

            if ( ++p == pe )
                goto _test_eof40;

        case 40:
            switch ( ( *p ) )
            {
            case 70:
                goto st42;

            case 83:
                goto st43;

            case 95:
                goto tr81;

            case 102:
                goto st42;

            case 115:
                goto st43;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr139;
tr77:

            {
                te = p + 1;
            }

            {
                act = 40;
            }
            goto st41;
tr80:

            {
                te = p + 1;
            }

            {
                act = 55;
            }
            goto st41;
tr81:

            {
                te = p + 1;
            }

            {
                act = 85;
            }
            goto st41;
tr84:

            {
                te = p + 1;
            }

            {
                act = 51;
            }
            goto st41;
tr85:

            {
                te = p + 1;
            }

            {
                act = 44;
            }
            goto st41;
tr88:

            {
                te = p + 1;
            }

            {
                act = 58;
            }
            goto st41;
tr90:

            {
                te = p + 1;
            }

            {
                act = 38;
            }
            goto st41;
tr147:

            {
                te = p + 1;
            }

            {
                act = 1;
            }
            goto st41;
tr149:

            {
                te = p + 1;
            }

            {
                act = 61;
            }
            goto st41;
tr151:

            {
                te = p + 1;
            }

            {
                act = 62;
            }
            goto st41;
tr157:

            {
                te = p + 1;
            }

            {
                act = 59;
            }
            goto st41;
tr158:

            {
                te = p + 1;
            }

            {
                act = 79;
            }
            goto st41;
tr161:

            {
                te = p + 1;
            }

            {
                act = 63;
            }
            goto st41;
tr163:

            {
                te = p + 1;
            }

            {
                act = 80;
            }
            goto st41;
tr166:

            {
                te = p + 1;
            }

            {
                act = 81;
            }
            goto st41;
tr169:

            {
                te = p + 1;
            }

            {
                act = 57;
            }
            goto st41;
tr171:

            {
                te = p + 1;
            }

            {
                act = 49;
            }
            goto st41;
tr172:

            {
                te = p + 1;
            }

            {
                act = 52;
            }
            goto st41;
tr174:

            {
                te = p + 1;
            }

            {
                act = 50;
            }
            goto st41;
tr175:

            {
                te = p + 1;
            }

            {
                act = 53;
            }
            goto st41;
tr176:

            {
                te = p + 1;
            }

            {
                act = 39;
            }
            goto st41;
tr178:

            {
                te = p + 1;
            }

            {
                act = 37;
            }
            goto st41;
tr179:

            {
                te = p + 1;
            }

            {
                act = 82;
            }
            goto st41;
tr181:

            {
                te = p + 1;
            }

            {
                act = 42;
            }
            goto st41;
tr182:

            {
                te = p + 1;
            }

            {
                act = 41;
            }
            goto st41;
tr183:

            {
                te = p + 1;
            }

            {
                act = 67;
            }
            goto st41;
st41:

            if ( ++p == pe )
                goto _test_eof41;

        case 41:

            if ( ( *p ) == 95 )
                goto tr81;

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr21;
st42:

            if ( ++p == pe )
                goto _test_eof42;

        case 42:
            switch ( ( *p ) )
            {
            case 39:
                goto tr143;

            case 95:
                goto tr81;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr142;
st43:

            if ( ++p == pe )
                goto _test_eof43;

        case 43:
            switch ( ( *p ) )
            {
            case 77:
                goto st44;

            case 95:
                goto tr81;

            case 109:
                goto st44;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr144;
st44:

            if ( ++p == pe )
                goto _test_eof44;

        case 44:
            switch ( ( *p ) )
            {
            case 80:
                goto st45;

            case 95:
                goto tr81;

            case 112:
                goto st45;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr144;
st45:

            if ( ++p == pe )
                goto _test_eof45;

        case 45:
            switch ( ( *p ) )
            {
            case 67:
                goto tr147;

            case 95:
                goto tr81;

            case 99:
                goto tr147;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr144;
st46:

            if ( ++p == pe )
                goto _test_eof46;

        case 46:
            switch ( ( *p ) )
            {
            case 67:
                goto tr149;

            case 95:
                goto tr81;

            case 99:
                goto tr149;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr148;
st47:

            if ( ++p == pe )
                goto _test_eof47;

        case 47:
            switch ( ( *p ) )
            {
            case 69:
                goto tr151;

            case 83:
                goto tr152;

            case 95:
                goto tr81;

            case 101:
                goto tr151;

            case 115:
                goto tr152;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr150;
tr152:

            {
                te = p + 1;
            }
            goto st48;
st48:

            if ( ++p == pe )
                goto _test_eof48;

        case 48:

            switch ( ( *p ) )
            {
            case 46:
                goto st18;

            case 95:
                goto tr81;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr144;
st18:

            if ( ++p == pe )
                goto _test_eof18;

        case 18:
            switch ( ( *p ) )
            {
            case 66:
                goto tr30;

            case 76:
                goto tr31;

            case 80:
                goto tr32;

            case 87:
                goto tr33;

            case 98:
                goto tr30;

            case 108:
                goto tr31;

            case 112:
                goto tr32;

            case 119:
                goto tr33;
            }

            goto tr29;
st49:

            if ( ++p == pe )
                goto _test_eof49;

        case 49:
            switch ( ( *p ) )
            {
            case 73:
                goto st50;

            case 88:
                goto st51;

            case 95:
                goto tr81;

            case 105:
                goto st50;

            case 120:
                goto st51;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr154;
st50:

            if ( ++p == pe )
                goto _test_eof50;

        case 50:
            switch ( ( *p ) )
            {
            case 82:
                goto tr157;

            case 95:
                goto tr81;

            case 114:
                goto tr157;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr144;
st51:

            if ( ++p == pe )
                goto _test_eof51;

        case 51:
            switch ( ( *p ) )
            {
            case 88:
                goto tr158;

            case 95:
                goto tr81;

            case 120:
                goto tr158;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr144;
st52:

            if ( ++p == pe )
                goto _test_eof52;

        case 52:
            switch ( ( *p ) )
            {
            case 65:
                goto st53;

            case 76:
                goto tr161;

            case 95:
                goto tr81;

            case 97:
                goto st53;

            case 108:
                goto tr161;
            }

            if ( ( *p ) < 66 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 98 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr159;
st53:

            if ( ++p == pe )
                goto _test_eof53;

        case 53:
            switch ( ( *p ) )
            {
            case 76:
                goto st54;

            case 95:
                goto tr81;

            case 108:
                goto st54;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr144;
st54:

            if ( ++p == pe )
                goto _test_eof54;

        case 54:
            switch ( ( *p ) )
            {
            case 84:
                goto tr163;

            case 95:
                goto tr81;

            case 116:
                goto tr163;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr144;
st55:

            if ( ++p == pe )
                goto _test_eof55;

        case 55:
            switch ( ( *p ) )
            {
            case 73:
                goto st56;

            case 77:
                goto tr166;

            case 88:
                goto st57;

            case 89:
                goto st58;

            case 95:
                goto tr81;

            case 105:
                goto st56;

            case 109:
                goto tr166;

            case 120:
                goto st57;

            case 121:
                goto st58;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr164;
st56:

            if ( ++p == pe )
                goto _test_eof56;

        case 56:
            switch ( ( *p ) )
            {
            case 82:
                goto tr169;

            case 95:
                goto tr81;

            case 114:
                goto tr169;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr144;
st57:

            if ( ++p == pe )
                goto _test_eof57;

        case 57:
            switch ( ( *p ) )
            {
            case 72:
                goto tr171;

            case 76:
                goto tr172;

            case 95:
                goto tr81;

            case 104:
                goto tr171;

            case 108:
                goto tr172;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr170;
st58:

            if ( ++p == pe )
                goto _test_eof58;

        case 58:
            switch ( ( *p ) )
            {
            case 72:
                goto tr174;

            case 76:
                goto tr175;

            case 95:
                goto tr81;

            case 104:
                goto tr174;

            case 108:
                goto tr175;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr173;
st59:

            if ( ++p == pe )
                goto _test_eof59;

        case 59:
            switch ( ( *p ) )
            {
            case 67:
                goto tr176;

            case 79:
                goto st60;

            case 90:
                goto tr178;

            case 95:
                goto tr81;

            case 99:
                goto tr176;

            case 111:
                goto st60;

            case 122:
                goto tr178;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 89 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 121 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr144;
st60:

            if ( ++p == pe )
                goto _test_eof60;

        case 60:
            switch ( ( *p ) )
            {
            case 80:
                goto tr179;

            case 95:
                goto tr81;

            case 112:
                goto tr179;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr144;
st61:

            if ( ++p == pe )
                goto _test_eof61;

        case 61:
            switch ( ( *p ) )
            {
            case 69:
                goto tr181;

            case 79:
                goto tr182;

            case 95:
                goto tr81;

            case 101:
                goto tr181;

            case 111:
                goto tr182;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr180;
st62:

            if ( ++p == pe )
                goto _test_eof62;

        case 62:
            switch ( ( *p ) )
            {
            case 80:
                goto tr183;

            case 95:
                goto tr81;

            case 112:
                goto tr183;
            }

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    goto tr81;
            }
            else if ( ( *p ) > 90 )
            {
                if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    goto tr81;
            }
            else
                goto tr81;

            goto tr144;
tr91:

            {
                te = p + 1;
            }
            goto st63;
st63:

            if ( ++p == pe )
                goto _test_eof63;

        case 63:

            _widec = ( *p );

            if ( ( *p ) < 65 )
            {
                if ( ( *p ) > 9 )
                {
                    if ( 32 <= ( *p ) && ( *p ) <= 32 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) >= 9 )
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 90 )
            {
                if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) >= 95 )
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 521:
                goto st19;

            case 544:
                goto st19;

            case 607:
                goto st64;
            }

            if ( _widec > 602 )
            {
                if ( 609 <= _widec && _widec <= 634 )
                    goto st64;
            }
            else if ( _widec >= 577 )
                goto st64;

            goto tr184;
st19:

            if ( ++p == pe )
                goto _test_eof19;

        case 19:
            _widec = ( *p );

            if ( ( *p ) < 65 )
            {
                if ( ( *p ) > 9 )
                {
                    if ( 32 <= ( *p ) && ( *p ) <= 32 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) >= 9 )
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 90 )
            {
                if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) >= 95 )
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 521:
                goto st19;

            case 544:
                goto st19;

            case 607:
                goto st64;
            }

            if ( _widec > 602 )
            {
                if ( 609 <= _widec && _widec <= 634 )
                    goto st64;
            }
            else if ( _widec >= 577 )
                goto st64;

            goto tr34;
st64:

            if ( ++p == pe )
                goto _test_eof64;

        case 64:
            _widec = ( *p );

            if ( ( *p ) < 65 )
            {
                if ( 48 <= ( *p ) && ( *p ) <= 57 )
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 90 )
            {
                if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) >= 95 )
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            if ( _widec == 607 )
                goto st64;

            if ( _widec < 577 )
            {
                if ( 560 <= _widec && _widec <= 569 )
                    goto st64;
            }
            else if ( _widec > 602 )
            {
                if ( 609 <= _widec && _widec <= 634 )
                    goto st64;
            }
            else
                goto st64;

            goto tr185;
tr92:

            {
                te = p + 1;
            }

            {
                act = 54;
            }
            goto st65;
st65:

            if ( ++p == pe )
                goto _test_eof65;

        case 65:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 326:
                goto st42;

            case 339:
                goto st43;

            case 351:
                goto tr81;

            case 358:
                goto st42;

            case 371:
                goto st43;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 582:
                goto tr186;

            case 595:
                goto tr187;

            case 607:
                goto tr98;

            case 614:
                goto tr186;

            case 627:
                goto tr187;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr139;
st20:

            if ( ++p == pe )
                goto _test_eof20;

        case 20:
            _widec = ( *p );

            if ( ( *p ) < 32 )
            {
                if ( 9 <= ( *p ) && ( *p ) <= 9 )
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 32 )
            {
                if ( 58 <= ( *p ) && ( *p ) <= 58 )
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;
            }

            goto tr21;
tr94:

            {
                te = p + 1;
            }

            {
                act = 40;
            }
            goto st66;
tr97:

            {
                te = p + 1;
            }

            {
                act = 55;
            }
            goto st66;
tr98:

            {
                te = p + 1;
            }

            {
                act = 85;
            }
            goto st66;
tr101:

            {
                te = p + 1;
            }

            {
                act = 51;
            }
            goto st66;
tr102:

            {
                te = p + 1;
            }

            {
                act = 44;
            }
            goto st66;
tr105:

            {
                te = p + 1;
            }

            {
                act = 58;
            }
            goto st66;
tr107:

            {
                te = p + 1;
            }

            {
                act = 38;
            }
            goto st66;
tr190:

            {
                te = p + 1;
            }

            {
                act = 1;
            }
            goto st66;
tr191:

            {
                te = p + 1;
            }

            {
                act = 61;
            }
            goto st66;
tr192:

            {
                te = p + 1;
            }

            {
                act = 62;
            }
            goto st66;
tr196:

            {
                te = p + 1;
            }

            {
                act = 59;
            }
            goto st66;
tr197:

            {
                te = p + 1;
            }

            {
                act = 79;
            }
            goto st66;
tr199:

            {
                te = p + 1;
            }

            {
                act = 63;
            }
            goto st66;
tr201:

            {
                te = p + 1;
            }

            {
                act = 80;
            }
            goto st66;
tr203:

            {
                te = p + 1;
            }

            {
                act = 81;
            }
            goto st66;
tr206:

            {
                te = p + 1;
            }

            {
                act = 57;
            }
            goto st66;
tr207:

            {
                te = p + 1;
            }

            {
                act = 49;
            }
            goto st66;
tr208:

            {
                te = p + 1;
            }

            {
                act = 52;
            }
            goto st66;
tr209:

            {
                te = p + 1;
            }

            {
                act = 50;
            }
            goto st66;
tr210:

            {
                te = p + 1;
            }

            {
                act = 53;
            }
            goto st66;
tr211:

            {
                te = p + 1;
            }

            {
                act = 39;
            }
            goto st66;
tr213:

            {
                te = p + 1;
            }

            {
                act = 37;
            }
            goto st66;
tr214:

            {
                te = p + 1;
            }

            {
                act = 82;
            }
            goto st66;
tr215:

            {
                te = p + 1;
            }

            {
                act = 42;
            }
            goto st66;
tr216:

            {
                te = p + 1;
            }

            {
                act = 41;
            }
            goto st66;
tr217:

            {
                te = p + 1;
            }

            {
                act = 67;
            }
            goto st66;
st66:

            if ( ++p == pe )
                goto _test_eof66;

        case 66:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 351:
                goto tr81;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 607:
                goto tr98;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr21;
tr186:

            {
                te = p + 1;
            }

            {
                act = 66;
            }
            goto st67;
st67:

            if ( ++p == pe )
                goto _test_eof67;

        case 67:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 39:
                goto tr143;

            case 351:
                goto tr81;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 607:
                goto tr98;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr142;
tr187:

            {
                te = p + 1;
            }

            {
                act = 85;
            }
            goto st68;
st68:

            if ( ++p == pe )
                goto _test_eof68;

        case 68:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 333:
                goto st44;

            case 351:
                goto tr81;

            case 365:
                goto st44;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 589:
                goto tr188;

            case 607:
                goto tr98;

            case 621:
                goto tr188;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr144;
tr188:

            {
                te = p + 1;
            }

            {
                act = 85;
            }
            goto st69;
st69:

            if ( ++p == pe )
                goto _test_eof69;

        case 69:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 336:
                goto st45;

            case 351:
                goto tr81;

            case 368:
                goto st45;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 592:
                goto tr189;

            case 607:
                goto tr98;

            case 624:
                goto tr189;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr144;
tr189:

            {
                te = p + 1;
            }

            {
                act = 85;
            }
            goto st70;
st70:

            if ( ++p == pe )
                goto _test_eof70;

        case 70:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 323:
                goto tr147;

            case 351:
                goto tr81;

            case 355:
                goto tr147;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 579:
                goto tr190;

            case 607:
                goto tr98;

            case 611:
                goto tr190;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr144;
tr93:

            {
                te = p + 1;
            }

            {
                act = 45;
            }
            goto st71;
st71:

            if ( ++p == pe )
                goto _test_eof71;

        case 71:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 323:
                goto tr149;

            case 351:
                goto tr81;

            case 355:
                goto tr149;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 579:
                goto tr191;

            case 607:
                goto tr98;

            case 611:
                goto tr191;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr148;
tr95:

            {
                te = p + 1;
            }

            {
                act = 46;
            }
            goto st72;
st72:

            if ( ++p == pe )
                goto _test_eof72;

        case 72:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 325:
                goto tr151;

            case 339:
                goto tr152;

            case 351:
                goto tr81;

            case 357:
                goto tr151;

            case 371:
                goto tr152;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 581:
                goto tr192;

            case 595:
                goto tr193;

            case 607:
                goto tr98;

            case 613:
                goto tr192;

            case 627:
                goto tr193;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr150;
tr193:

            {
                te = p + 1;
            }

            {
                act = 85;
            }
            goto st73;
st73:

            if ( ++p == pe )
                goto _test_eof73;

        case 73:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 46:
                goto st18;

            case 351:
                goto tr81;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 607:
                goto tr98;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr144;
tr96:

            {
                te = p + 1;
            }

            {
                act = 47;
            }
            goto st74;
st74:

            if ( ++p == pe )
                goto _test_eof74;

        case 74:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 329:
                goto st50;

            case 344:
                goto st51;

            case 351:
                goto tr81;

            case 361:
                goto st50;

            case 376:
                goto st51;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 585:
                goto tr194;

            case 600:
                goto tr195;

            case 607:
                goto tr98;

            case 617:
                goto tr194;

            case 632:
                goto tr195;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr154;
tr194:

            {
                te = p + 1;
            }

            {
                act = 85;
            }
            goto st75;
st75:

            if ( ++p == pe )
                goto _test_eof75;

        case 75:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 338:
                goto tr157;

            case 351:
                goto tr81;

            case 370:
                goto tr157;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 594:
                goto tr196;

            case 607:
                goto tr98;

            case 626:
                goto tr196;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr144;
tr195:

            {
                te = p + 1;
            }

            {
                act = 85;
            }
            goto st76;
st76:

            if ( ++p == pe )
                goto _test_eof76;

        case 76:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 344:
                goto tr158;

            case 351:
                goto tr81;

            case 376:
                goto tr158;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 600:
                goto tr197;

            case 607:
                goto tr98;

            case 632:
                goto tr197;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr144;
tr99:

            {
                te = p + 1;
            }

            {
                act = 48;
            }
            goto st77;
st77:

            if ( ++p == pe )
                goto _test_eof77;

        case 77:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 321:
                goto st53;

            case 332:
                goto tr161;

            case 351:
                goto tr81;

            case 353:
                goto st53;

            case 364:
                goto tr161;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 577:
                goto tr198;

            case 588:
                goto tr199;

            case 607:
                goto tr98;

            case 609:
                goto tr198;

            case 620:
                goto tr199;
            }

            if ( _widec < 354 )
            {
                if ( _widec > 313 )
                {
                    if ( 322 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 578 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 610 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr159;
tr198:

            {
                te = p + 1;
            }

            {
                act = 85;
            }
            goto st78;
st78:

            if ( ++p == pe )
                goto _test_eof78;

        case 78:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 332:
                goto st54;

            case 351:
                goto tr81;

            case 364:
                goto st54;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 588:
                goto tr200;

            case 607:
                goto tr98;

            case 620:
                goto tr200;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr144;
tr200:

            {
                te = p + 1;
            }

            {
                act = 85;
            }
            goto st79;
st79:

            if ( ++p == pe )
                goto _test_eof79;

        case 79:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 340:
                goto tr163;

            case 351:
                goto tr81;

            case 372:
                goto tr163;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 596:
                goto tr201;

            case 607:
                goto tr98;

            case 628:
                goto tr201;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr144;
tr100:

            {
                te = p + 1;
            }

            {
                act = 56;
            }
            goto st80;
st80:

            if ( ++p == pe )
                goto _test_eof80;

        case 80:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 329:
                goto st56;

            case 333:
                goto tr166;

            case 344:
                goto st57;

            case 345:
                goto st58;

            case 351:
                goto tr81;

            case 361:
                goto st56;

            case 365:
                goto tr166;

            case 376:
                goto st57;

            case 377:
                goto st58;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 585:
                goto tr202;

            case 589:
                goto tr203;

            case 600:
                goto tr204;

            case 601:
                goto tr205;

            case 607:
                goto tr98;

            case 617:
                goto tr202;

            case 621:
                goto tr203;

            case 632:
                goto tr204;

            case 633:
                goto tr205;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr164;
tr202:

            {
                te = p + 1;
            }

            {
                act = 85;
            }
            goto st81;
st81:

            if ( ++p == pe )
                goto _test_eof81;

        case 81:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 338:
                goto tr169;

            case 351:
                goto tr81;

            case 370:
                goto tr169;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 594:
                goto tr206;

            case 607:
                goto tr98;

            case 626:
                goto tr206;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr144;
tr204:

            {
                te = p + 1;
            }

            {
                act = 64;
            }
            goto st82;
st82:

            if ( ++p == pe )
                goto _test_eof82;

        case 82:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 328:
                goto tr171;

            case 332:
                goto tr172;

            case 351:
                goto tr81;

            case 360:
                goto tr171;

            case 364:
                goto tr172;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 584:
                goto tr207;

            case 588:
                goto tr208;

            case 607:
                goto tr98;

            case 616:
                goto tr207;

            case 620:
                goto tr208;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr170;
tr205:

            {
                te = p + 1;
            }

            {
                act = 65;
            }
            goto st83;
st83:

            if ( ++p == pe )
                goto _test_eof83;

        case 83:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 328:
                goto tr174;

            case 332:
                goto tr175;

            case 351:
                goto tr81;

            case 360:
                goto tr174;

            case 364:
                goto tr175;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 584:
                goto tr209;

            case 588:
                goto tr210;

            case 607:
                goto tr98;

            case 616:
                goto tr209;

            case 620:
                goto tr210;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr173;
tr103:

            {
                te = p + 1;
            }

            {
                act = 85;
            }
            goto st84;
st84:

            if ( ++p == pe )
                goto _test_eof84;

        case 84:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 323:
                goto tr176;

            case 335:
                goto st60;

            case 346:
                goto tr178;

            case 351:
                goto tr81;

            case 355:
                goto tr176;

            case 367:
                goto st60;

            case 378:
                goto tr178;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 579:
                goto tr211;

            case 591:
                goto tr212;

            case 602:
                goto tr213;

            case 607:
                goto tr98;

            case 611:
                goto tr211;

            case 623:
                goto tr212;

            case 634:
                goto tr213;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 345 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 377 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 601 )
                {
                    if ( 609 <= _widec && _widec <= 633 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr144;
tr212:

            {
                te = p + 1;
            }

            {
                act = 85;
            }
            goto st85;
st85:

            if ( ++p == pe )
                goto _test_eof85;

        case 85:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 336:
                goto tr179;

            case 351:
                goto tr81;

            case 368:
                goto tr179;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 592:
                goto tr214;

            case 607:
                goto tr98;

            case 624:
                goto tr214;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr144;
tr104:

            {
                te = p + 1;
            }

            {
                act = 43;
            }
            goto st86;
st86:

            if ( ++p == pe )
                goto _test_eof86;

        case 86:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 325:
                goto tr181;

            case 335:
                goto tr182;

            case 351:
                goto tr81;

            case 357:
                goto tr181;

            case 367:
                goto tr182;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 581:
                goto tr215;

            case 591:
                goto tr216;

            case 607:
                goto tr98;

            case 613:
                goto tr215;

            case 623:
                goto tr216;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr180;
tr106:

            {
                te = p + 1;
            }

            {
                act = 85;
            }
            goto st87;
st87:

            if ( ++p == pe )
                goto _test_eof87;

        case 87:

            _widec = ( *p );

            if ( ( *p ) < 58 )
            {
                if ( ( *p ) < 32 )
                {
                    if ( 9 <= ( *p ) && ( *p ) <= 9 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 32 )
                {
                    if ( 48 <= ( *p ) && ( *p ) <= 57 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else if ( ( *p ) > 58 )
            {
                if ( ( *p ) < 95 )
                {
                    if ( 65 <= ( *p ) && ( *p ) <= 90 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else if ( ( *p ) > 95 )
                {
                    if ( 97 <= ( *p ) && ( *p ) <= 122 )
                    {
                        _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                        if (

                            at_bol ) _widec += 256;
                    }
                }
                else
                {
                    _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                    if (

                        at_bol ) _widec += 256;
                }
            }
            else
            {
                _widec = ( short )( 128 + ( ( *p ) - -128 ) );

                if (

                    at_bol ) _widec += 256;
            }

            switch ( _widec )
            {
            case 336:
                goto tr183;

            case 351:
                goto tr81;

            case 368:
                goto tr183;

            case 521:
                goto st20;

            case 544:
                goto st20;

            case 570:
                goto tr38;

            case 592:
                goto tr217;

            case 607:
                goto tr98;

            case 624:
                goto tr217;
            }

            if ( _widec < 353 )
            {
                if ( _widec > 313 )
                {
                    if ( 321 <= _widec && _widec <= 346 )
                        goto tr81;
                }
                else if ( _widec >= 304 )
                    goto tr81;
            }
            else if ( _widec > 378 )
            {
                if ( _widec < 577 )
                {
                    if ( 560 <= _widec && _widec <= 569 )
                        goto tr98;
                }
                else if ( _widec > 602 )
                {
                    if ( 609 <= _widec && _widec <= 634 )
                        goto tr98;
                }
                else
                    goto tr98;
            }
            else
                goto tr81;

            goto tr144;
        }

_test_eof21:
        cs = 21;
        goto _test_eof;
_test_eof22:
        cs = 22;
        goto _test_eof;
_test_eof23:
        cs = 23;
        goto _test_eof;
_test_eof24:
        cs = 24;
        goto _test_eof;
_test_eof25:
        cs = 25;
        goto _test_eof;
_test_eof1:
        cs = 1;
        goto _test_eof;
_test_eof2:
        cs = 2;
        goto _test_eof;
_test_eof3:
        cs = 3;
        goto _test_eof;
_test_eof4:
        cs = 4;
        goto _test_eof;
_test_eof5:
        cs = 5;
        goto _test_eof;
_test_eof6:
        cs = 6;
        goto _test_eof;
_test_eof7:
        cs = 7;
        goto _test_eof;
_test_eof8:
        cs = 8;
        goto _test_eof;
_test_eof9:
        cs = 9;
        goto _test_eof;
_test_eof10:
        cs = 10;
        goto _test_eof;
_test_eof11:
        cs = 11;
        goto _test_eof;
_test_eof12:
        cs = 12;
        goto _test_eof;
_test_eof13:
        cs = 13;
        goto _test_eof;
_test_eof26:
        cs = 26;
        goto _test_eof;
_test_eof27:
        cs = 27;
        goto _test_eof;
_test_eof28:
        cs = 28;
        goto _test_eof;
_test_eof29:
        cs = 29;
        goto _test_eof;
_test_eof14:
        cs = 14;
        goto _test_eof;
_test_eof30:
        cs = 30;
        goto _test_eof;
_test_eof31:
        cs = 31;
        goto _test_eof;
_test_eof15:
        cs = 15;
        goto _test_eof;
_test_eof32:
        cs = 32;
        goto _test_eof;
_test_eof33:
        cs = 33;
        goto _test_eof;
_test_eof34:
        cs = 34;
        goto _test_eof;
_test_eof35:
        cs = 35;
        goto _test_eof;
_test_eof36:
        cs = 36;
        goto _test_eof;
_test_eof37:
        cs = 37;
        goto _test_eof;
_test_eof16:
        cs = 16;
        goto _test_eof;
_test_eof17:
        cs = 17;
        goto _test_eof;
_test_eof38:
        cs = 38;
        goto _test_eof;
_test_eof39:
        cs = 39;
        goto _test_eof;
_test_eof40:
        cs = 40;
        goto _test_eof;
_test_eof41:
        cs = 41;
        goto _test_eof;
_test_eof42:
        cs = 42;
        goto _test_eof;
_test_eof43:
        cs = 43;
        goto _test_eof;
_test_eof44:
        cs = 44;
        goto _test_eof;
_test_eof45:
        cs = 45;
        goto _test_eof;
_test_eof46:
        cs = 46;
        goto _test_eof;
_test_eof47:
        cs = 47;
        goto _test_eof;
_test_eof48:
        cs = 48;
        goto _test_eof;
_test_eof18:
        cs = 18;
        goto _test_eof;
_test_eof49:
        cs = 49;
        goto _test_eof;
_test_eof50:
        cs = 50;
        goto _test_eof;
_test_eof51:
        cs = 51;
        goto _test_eof;
_test_eof52:
        cs = 52;
        goto _test_eof;
_test_eof53:
        cs = 53;
        goto _test_eof;
_test_eof54:
        cs = 54;
        goto _test_eof;
_test_eof55:
        cs = 55;
        goto _test_eof;
_test_eof56:
        cs = 56;
        goto _test_eof;
_test_eof57:
        cs = 57;
        goto _test_eof;
_test_eof58:
        cs = 58;
        goto _test_eof;
_test_eof59:
        cs = 59;
        goto _test_eof;
_test_eof60:
        cs = 60;
        goto _test_eof;
_test_eof61:
        cs = 61;
        goto _test_eof;
_test_eof62:
        cs = 62;
        goto _test_eof;
_test_eof63:
        cs = 63;
        goto _test_eof;
_test_eof19:
        cs = 19;
        goto _test_eof;
_test_eof64:
        cs = 64;
        goto _test_eof;
_test_eof65:
        cs = 65;
        goto _test_eof;
_test_eof20:
        cs = 20;
        goto _test_eof;
_test_eof66:
        cs = 66;
        goto _test_eof;
_test_eof67:
        cs = 67;
        goto _test_eof;
_test_eof68:
        cs = 68;
        goto _test_eof;
_test_eof69:
        cs = 69;
        goto _test_eof;
_test_eof70:
        cs = 70;
        goto _test_eof;
_test_eof71:
        cs = 71;
        goto _test_eof;
_test_eof72:
        cs = 72;
        goto _test_eof;
_test_eof73:
        cs = 73;
        goto _test_eof;
_test_eof74:
        cs = 74;
        goto _test_eof;
_test_eof75:
        cs = 75;
        goto _test_eof;
_test_eof76:
        cs = 76;
        goto _test_eof;
_test_eof77:
        cs = 77;
        goto _test_eof;
_test_eof78:
        cs = 78;
        goto _test_eof;
_test_eof79:
        cs = 79;
        goto _test_eof;
_test_eof80:
        cs = 80;
        goto _test_eof;
_test_eof81:
        cs = 81;
        goto _test_eof;
_test_eof82:
        cs = 82;
        goto _test_eof;
_test_eof83:
        cs = 83;
        goto _test_eof;
_test_eof84:
        cs = 84;
        goto _test_eof;
_test_eof85:
        cs = 85;
        goto _test_eof;
_test_eof86:
        cs = 86;
        goto _test_eof;
_test_eof87:
        cs = 87;
        goto _test_eof;

_test_eof:
        {}

        if ( p == eof )
        {
            switch ( cs )
            {
            case 22:
                goto tr108;

            case 23:
                goto tr21;

            case 24:
                goto tr111;

            case 25:
                goto tr113;

            case 1:
                goto tr0;

            case 2:
                goto tr0;

            case 3:
                goto tr0;

            case 4:
                goto tr0;

            case 5:
                goto tr0;

            case 6:
                goto tr0;

            case 7:
                goto tr0;

            case 8:
                goto tr0;

            case 9:
                goto tr0;

            case 10:
                goto tr0;

            case 11:
                goto tr0;

            case 12:
                goto tr0;

            case 13:
                goto tr0;

            case 26:
                goto tr114;

            case 27:
                goto tr116;

            case 28:
                goto tr116;

            case 29:
                goto tr116;

            case 14:
                goto tr21;

            case 30:
                goto tr120;

            case 31:
                goto tr21;

            case 15:
                goto tr24;

            case 32:
                goto tr122;

            case 33:
                goto tr123;

            case 34:
                goto tr124;

            case 35:
                goto tr128;

            case 36:
                goto tr130;

            case 37:
                goto tr133;

            case 16:
                goto tr26;

            case 17:
                goto tr26;

            case 38:
                goto tr136;

            case 39:
                goto tr137;

            case 40:
                goto tr139;

            case 41:
                goto tr21;

            case 42:
                goto tr142;

            case 43:
                goto tr144;

            case 44:
                goto tr144;

            case 45:
                goto tr144;

            case 46:
                goto tr148;

            case 47:
                goto tr150;

            case 48:
                goto tr144;

            case 18:
                goto tr29;

            case 49:
                goto tr154;

            case 50:
                goto tr144;

            case 51:
                goto tr144;

            case 52:
                goto tr159;

            case 53:
                goto tr144;

            case 54:
                goto tr144;

            case 55:
                goto tr164;

            case 56:
                goto tr144;

            case 57:
                goto tr170;

            case 58:
                goto tr173;

            case 59:
                goto tr144;

            case 60:
                goto tr144;

            case 61:
                goto tr180;

            case 62:
                goto tr144;

            case 63:
                goto tr184;

            case 19:
                goto tr34;

            case 64:
                goto tr185;

            case 65:
                goto tr139;

            case 20:
                goto tr21;

            case 66:
                goto tr21;

            case 67:
                goto tr142;

            case 68:
                goto tr144;

            case 69:
                goto tr144;

            case 70:
                goto tr144;

            case 71:
                goto tr148;

            case 72:
                goto tr150;

            case 73:
                goto tr144;

            case 74:
                goto tr154;

            case 75:
                goto tr144;

            case 76:
                goto tr144;

            case 77:
                goto tr159;

            case 78:
                goto tr144;

            case 79:
                goto tr144;

            case 80:
                goto tr164;

            case 81:
                goto tr144;

            case 82:
                goto tr170;

            case 83:
                goto tr173;

            case 84:
                goto tr144;

            case 85:
                goto tr144;

            case 86:
                goto tr180;

            case 87:
                goto tr144;
            }
        }

_out:
        {}
    }


    return sym.tok;
}
