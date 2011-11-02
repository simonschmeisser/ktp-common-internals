/*
 * This file is part of telepathy-accounts-kcm
 *
 * Copyright (C) 2011 David Edmundson <kde@davidedmundson.co.uk>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef WALLETINTERFACE_H
#define WALLETINTERFACE_H

#include <TelepathyQt4/Account>

#include <KWallet/Wallet>

#include <QScopedPointer>

namespace KTelepathy
{

class WalletInterface
{
public:

    WalletInterface(WId winId);
    virtual ~WalletInterface();

    /** Returns true if a password is stored for the given account */
    bool hasPassword(const Tp::AccountPtr &account) const;

    /** Returns the stored password for the given account */
    QString password(const Tp::AccountPtr &account) const;

    /** Set the password for the given account to a new password */
    void setPassword(const Tp::AccountPtr &account, const QString &password);

    /** Remove the password for the given account from kwallet */
    void removePassword(const Tp::AccountPtr &account);

    /** Returns true if a given entry is stored for the given account */
    bool hasEntry(const Tp::AccountPtr &account, const QString &key) const;

    /** Returns the stored entry for the given account */
    QString entry(const Tp::AccountPtr &account, const QString &key) const;

    /** Set an entry for the given account to a new value */
    void setEntry(const Tp::AccountPtr &account, const QString &key, const QString &value);

    /** Remove the entry for the given account from kwallet */
    void removeEntry(const Tp::AccountPtr &account, const QString &key);

    /** Remove all the entries for the given account from kwallet */
    void removeAllEntries(const Tp::AccountPtr &account);

    /** Remove entries and password for the account from kwallet */
    void removeAccount(const Tp::AccountPtr &account);

    /** Determine if the wallet is open, and is a valid wallet handle */
    bool isOpen() const;

private:
    static const QLatin1String s_folderName;
    static const QLatin1String s_mapsPrefix;

    //TODO Library: move private members in a private class
    QScopedPointer<KWallet::Wallet> m_wallet;

};

} // namespace KTelepathy

#endif // WALLETINTERFACE_H