<%@ Page Language="C#" AutoEventWireup="true" CodeFile="rootChose.aspx.cs" Inherits="rootChose" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body style="background-color:#F2F2F2">
    <form id="form1" runat="server">
    <div style="text-align: center">
    
        <br />
        <br />
        <asp:Label ID="Label1" runat="server" Font-Size="25pt" ForeColor="#CC33FF" Text="欢迎登陆！管理员  请选择操作类型："></asp:Label>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <br />
        <br />
        <br />
        <br />
        <table style="width:400px; margin:auto;text-align: center">
        
            <tr>
                <td>
                    <asp:Button ID="Button1" runat="server" Text="用户信息管理" Height="60px" Width="120px" OnClick="Button1_Click" />
                </td>
                <td>
                    <asp:Button ID="Button2" runat="server" Text="医生信息管理" Height="60px" Width="120px" OnClick="Button2_Click" />
                </td>
            </tr>

            <tr>
                <td>
                    <br />
                </td>
                <td>
                    <br />
                </td>
            </tr>
            
            <tr>
                <td>
                    <asp:Button ID="Button3" runat="server" Text="科室信息管理" Height="60px" Width="120px" OnClick="Button3_Click" />
                </td>
                <td>
                    <asp:Button ID="Button4" runat="server" Text="疾病信息管理" Height="60px" Width="120px" />
                </td>
            </tr>
        </table>
    
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    
        </div>
    </form>
</body>
</html>
