/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> llc_phy_upd.o -> r_llc_loc_phy_upd_proc_continue_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_loc_phy_upd_proc_continue_hack(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  undefined1 uVar7;
  short sVar8;
  bool bVar9;
  int iVar10;
  code *UNRECOVERED_JUMPTABLE_00;
  short sVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  byte bVar15;
  undefined4 uVar16;
  undefined1 uVar17;
  
  iVar10 = *(int *)(&llc_env + param_1 * 4);
  iVar12 = (**(code **)(_r_ip_funcs_p + 0x674))(0,*(code **)(_r_ip_funcs_p + 0x674));
  uVar1 = *(undefined1 *)(iVar10 + 0x1c);
  uVar2 = *(undefined1 *)(iVar10 + 0x1d);
  if (param_3 == 0) {
    iVar13 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
    if (iVar13 != param_2) {
      UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_plf_funcs_p + 0x10);
      param_1 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar12,*(code **)(_r_ip_funcs_p + 0x680));
      uVar16 = 0x9c;
_L133:
                    /* WARNING: Could not recover jumptable at 0x0001052c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)(param_1,param_2,"llc_phy_upd.c",uVar16,UNRECOVERED_JUMPTABLE_00);
      return;
    }
    uVar16 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar12,*(code **)(_r_ip_funcs_p + 0x680));
    switch(uVar16) {
    case 0:
      sVar11 = *(short *)(iVar10 + 0x24);
      *(ushort *)(iVar10 + 0x42) = *(ushort *)(iVar10 + 0x42) | 0x10;
      bVar15 = *(byte *)(iVar12 + 0xb);
      *(byte *)(iVar10 + 0x27) = bVar15;
      bVar3 = *(byte *)(iVar12 + 10);
      bVar4 = (&co_phy_value_to_mask)[*(byte *)(iVar10 + 0x1d)];
      *(byte *)(iVar10 + 0x26) = bVar3;
      sVar8 = *(short *)(iVar12 + 0x10);
      *(short *)(iVar10 + 0x24) = sVar8;
      if (((bVar4 & bVar15) == 0) ||
         (((&co_phy_value_to_mask)[*(byte *)(iVar10 + 0x1c)] & bVar3) == 0)) {
        llc_ll_phy_req_pdu_send(param_1);
        (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,1,*(code **)(_r_ip_funcs_p + 0x68c));
        if ((*(ushort *)(iVar10 + 0x42) & 1) == 0) {
          if ((*(byte *)(iVar12 + 10) & 4) == 0) {
            bVar15 = ~*(byte *)(iVar12 + 10) & 1;
          }
          else {
            bVar15 = 2;
            if (*(short *)(iVar12 + 0x10) != 2) {
              bVar15 = 3;
            }
          }
          (**(code **)(_r_ip_funcs_p + 0x3cc))(param_1,bVar15,*(code **)(_r_ip_funcs_p + 0x3cc));
          uVar16 = 3;
          UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x684);
        }
        else {
          uVar16 = 2;
          UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x684);
        }
        goto _L134;
      }
      if ((*(byte *)(iVar10 + 0x1c) != 3) || ((sVar8 == 0 || (sVar8 == sVar11)))) goto _L47;
      uVar17 = (&co_phy_to_rate)[*(byte *)(iVar10 + 0x1d)];
      uVar16 = 3;
      if (sVar8 == 2) {
        uVar16 = 2;
      }
      uVar14 = (**(code **)(_r_ip_funcs_p + 0x338))(param_1,*(code **)(_r_ip_funcs_p + 0x338));
      UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x37c);
      *(short *)(iVar12 + 8) = (short)uVar14;
      param_3 = (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar16,uVar17,uVar14,UNRECOVERED_JUMPTABLE_00);
      if (param_3 != 0) {
        *(undefined2 *)(iVar12 + 8) = 0;
        *(undefined2 *)(iVar12 + 0xc) = 0;
        goto _L47;
      }
      break;
    case 2:
      (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x68c));
    case 1:
      bVar15 = *(byte *)(iVar12 + 10);
      if (bVar15 != 0) {
        if (((&co_phy_value_to_mask)[*(byte *)(iVar10 + 0x1c)] & bVar15) == 0) {
          if ((bVar15 & 2) == 0) {
            if ((bVar15 & 1) == 0) {
              uVar17 = 4;
            }
            else {
              uVar17 = 1;
            }
          }
          else {
            uVar17 = 2;
          }
          *(undefined1 *)(iVar12 + 0xc) = uVar17;
        }
        else {
          *(undefined1 *)(iVar12 + 0xc) = 0;
        }
      }
      bVar15 = *(byte *)(iVar12 + 0xb);
      if (bVar15 != 0) {
        if (((&co_phy_value_to_mask)[*(byte *)(iVar10 + 0x1d)] & bVar15) == 0) {
          if ((bVar15 & 2) == 0) {
            if ((bVar15 & 1) == 0) {
              uVar17 = 4;
            }
            else {
              uVar17 = 1;
            }
          }
          else {
            uVar17 = 2;
          }
          *(undefined1 *)(iVar12 + 0xd) = uVar17;
        }
        else {
          *(undefined1 *)(iVar12 + 0xd) = 0;
        }
      }
      if (*(char *)(iVar12 + 0xf) != '\0') {
        if (*(byte *)(iVar12 + 0xc) == 0) {
          cVar5 = *(char *)(iVar10 + 0x1c);
        }
        else {
          cVar5 = (&co_phy_mask_to_value)[*(byte *)(iVar12 + 0xc)];
        }
        if (*(byte *)(iVar12 + 0xd) == 0) {
          cVar6 = *(char *)(iVar10 + 0x1d);
        }
        else {
          cVar6 = (&co_phy_mask_to_value)[*(byte *)(iVar12 + 0xd)];
        }
        if (cVar5 != cVar6) {
          *(undefined2 *)(iVar12 + 0xc) = 0;
        }
      }
      bVar9 = true;
      if (*(short *)(iVar12 + 0xc) != 0) {
        if (*(byte *)(iVar12 + 0xc) == 0) {
          bVar15 = *(byte *)(iVar10 + 0x1c);
        }
        else {
          bVar15 = (&co_phy_mask_to_value)[*(byte *)(iVar12 + 0xc)];
        }
        uVar17 = (&co_phy_to_rate)[bVar15];
        if ((bVar15 == 3) && (*(short *)(iVar12 + 0x10) == 2)) {
          uVar17 = 2;
        }
        if (*(byte *)(iVar12 + 0xd) == 0) {
          bVar15 = *(byte *)(iVar10 + 0x1d);
        }
        else {
          bVar15 = (&co_phy_mask_to_value)[*(byte *)(iVar12 + 0xd)];
        }
        uVar7 = (&co_phy_to_rate)[bVar15];
        sVar11 = (**(code **)(_r_ip_funcs_p + 0x338))(param_1,*(code **)(_r_ip_funcs_p + 0x338));
        UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x37c);
        *(short *)(iVar12 + 8) = sVar11 + *(short *)(iVar10 + 0x10) + 9;
        param_3 = (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar17,uVar7,UNRECOVERED_JUMPTABLE_00);
        if (param_3 == 0) {
          bVar9 = false;
          (**(code **)(_r_ip_funcs_p + 0x684))(iVar12,param_1,4,*(code **)(_r_ip_funcs_p + 0x684));
        }
        else {
          *(undefined2 *)(iVar12 + 8) = 0;
          *(undefined2 *)(iVar12 + 0xc) = 0;
          bVar9 = true;
        }
      }
      llc_llcp_phy_upd_ind_pdu_send
                (param_1,*(undefined1 *)(iVar12 + 0xc),*(undefined1 *)(iVar12 + 0xd),
                 *(undefined2 *)(iVar12 + 8));
      if (!bVar9) {
        return;
      }
_L47:
      iVar13 = _r_ip_funcs_p;
      *(ushort *)(iVar10 + 0x42) = *(ushort *)(iVar10 + 0x42) & 0xffef;
      if ((*(uint *)(iVar12 + 0xc) & 0xffffff) != 0) {
        (**(code **)(iVar13 + 0x644))
                  (param_1,param_3,*(undefined1 *)(iVar10 + 0x1c),*(undefined1 *)(iVar10 + 0x1d),
                   *(code **)(iVar13 + 0x644));
        (**(code **)(_r_ip_funcs_p + 0x640))(param_1,uVar1,uVar2,*(code **)(_r_ip_funcs_p + 0x640));
        if (*(char *)(iVar12 + 0xe) != '\0') {
          *(byte *)(iVar10 + 0x45) = *(byte *)(iVar10 + 0x45) & 0xbf;
        }
      }
                    /* WARNING: Could not recover jumptable at 0x00010664. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x690))(param_1,0,*(code **)(_r_ip_funcs_p + 0x690));
      return;
    case 3:
      (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x68c));
      if (*(short *)(iVar12 + 0xc) == 0) goto _L132;
      if (*(byte *)(iVar12 + 0xd) == 0) {
        bVar15 = *(byte *)(iVar10 + 0x1c);
      }
      else {
        bVar15 = (&co_phy_mask_to_value)[*(byte *)(iVar12 + 0xd)];
      }
      uVar17 = (&co_phy_to_rate)[bVar15];
      if ((bVar15 == 3) && (*(short *)(iVar12 + 0x10) == 2)) {
        uVar17 = 2;
      }
      if (*(byte *)(iVar12 + 0xc) == 0) {
        bVar15 = *(byte *)(iVar10 + 0x1d);
      }
      else {
        bVar15 = (&co_phy_mask_to_value)[*(byte *)(iVar12 + 0xc)];
      }
      param_3 = (**(code **)(_r_ip_funcs_p + 0x37c))
                          (param_1,uVar17,(&co_phy_to_rate)[bVar15],*(undefined2 *)(iVar12 + 8),
                           *(code **)(_r_ip_funcs_p + 0x37c));
      if (param_3 != 0) {
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (*(undefined1 *)(iVar12 + 0xd),*(undefined1 *)(iVar12 + 0xc),"llc_phy_upd.c",0x1a2
                   ,*(code **)(_r_plf_funcs_p + 0xc));
        goto _L47;
      }
      break;
    case 4:
      if (*(byte *)(iVar12 + 0xc) != 0) {
        if ((*(ushort *)(iVar10 + 0x42) & 1) == 0) {
          *(undefined *)(iVar10 + 0x1d) = (&co_phy_mask_to_value)[*(byte *)(iVar12 + 0xc)];
        }
        else {
          *(undefined *)(iVar10 + 0x1c) = (&co_phy_mask_to_value)[*(byte *)(iVar12 + 0xc)];
        }
      }
      if (*(byte *)(iVar12 + 0xd) != 0) {
        if ((*(ushort *)(iVar10 + 0x42) & 1) == 0) {
          *(undefined *)(iVar10 + 0x1c) = (&co_phy_mask_to_value)[*(byte *)(iVar12 + 0xd)];
        }
        else {
          *(undefined *)(iVar10 + 0x1d) = (&co_phy_mask_to_value)[*(byte *)(iVar12 + 0xd)];
        }
      }
      goto _L47;
    default:
      UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_plf_funcs_p + 0xc);
      param_2 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar12,*(code **)(_r_ip_funcs_p + 0x680));
      uVar16 = 0x1ca;
      goto _L133;
    }
    uVar16 = 4;
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x684);
_L134:
                    /* WARNING: Could not recover jumptable at 0x000106aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(iVar12,param_1,uVar16,UNRECOVERED_JUMPTABLE_00);
    return;
  }
  (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x68c));
_L132:
  (**(code **)(_r_ip_funcs_p + 0x3cc))(param_1,4,*(code **)(_r_ip_funcs_p + 0x3cc));
  goto _L47;
}

