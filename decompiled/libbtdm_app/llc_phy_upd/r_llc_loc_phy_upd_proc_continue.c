/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> llc_phy_upd.o -> r_llc_loc_phy_upd_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_loc_phy_upd_proc_continue(int param_1,int param_2,int param_3)

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
  code *pcVar11;
  short sVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  byte bVar17;
  undefined1 uVar18;
  
  iVar10 = *(int *)(&llc_env + param_1 * 4);
  iVar13 = (**(code **)(_r_ip_funcs_p + 0x674))(0,*(code **)(_r_ip_funcs_p + 0x674));
  uVar1 = *(undefined1 *)(iVar10 + 0x1c);
  uVar2 = *(undefined1 *)(iVar10 + 0x1d);
  iVar14 = (**(code **)(_r_ip_funcs_p + 0x7e4))
                     (1,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x7e4));
  if (iVar14 != 0) {
    return;
  }
  if (param_3 != 0) {
    (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x68c));
_L88:
    (**(code **)(_r_ip_funcs_p + 0x3cc))(param_1,4,*(code **)(_r_ip_funcs_p + 0x3cc));
    goto _L4;
  }
  iVar14 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar13,*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar14 != param_2) {
    pcVar11 = *(code **)(_r_plf_funcs_p + 0x10);
    (**(code **)(_r_ip_funcs_p + 0x680))(iVar13,*(code **)(_r_ip_funcs_p + 0x680));
    (*pcVar11)(param_2,"llc_phy_upd.c",0x9d);
    goto _L6;
  }
  uVar15 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar13,*(code **)(_r_ip_funcs_p + 0x680));
  switch(uVar15) {
  case 0:
    sVar12 = *(short *)(iVar10 + 0x24);
    *(ushort *)(iVar10 + 0x42) = *(ushort *)(iVar10 + 0x42) | 0x10;
    bVar17 = *(byte *)(iVar13 + 0xb);
    *(byte *)(iVar10 + 0x27) = bVar17;
    bVar3 = *(byte *)(iVar13 + 10);
    bVar4 = (&co_phy_value_to_mask)[*(byte *)(iVar10 + 0x1d)];
    *(byte *)(iVar10 + 0x26) = bVar3;
    sVar8 = *(short *)(iVar13 + 0x10);
    *(short *)(iVar10 + 0x24) = sVar8;
    if (((bVar4 & bVar17) == 0) ||
       (((&co_phy_value_to_mask)[*(byte *)(iVar10 + 0x1c)] & bVar3) == 0)) {
      llc_ll_phy_req_pdu_send(param_1);
      (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,1,*(code **)(_r_ip_funcs_p + 0x68c));
      if ((*(ushort *)(iVar10 + 0x42) & 1) == 0) {
        if ((*(byte *)(iVar13 + 10) & 4) == 0) {
          bVar17 = ~*(byte *)(iVar13 + 10) & 1;
        }
        else {
          bVar17 = 2;
          if (*(short *)(iVar13 + 0x10) != 2) {
            bVar17 = 3;
          }
        }
        (**(code **)(_r_ip_funcs_p + 0x3cc))(param_1,bVar17,*(code **)(_r_ip_funcs_p + 0x3cc));
        uVar15 = 3;
        pcVar11 = *(code **)(_r_ip_funcs_p + 0x684);
      }
      else {
        uVar15 = 2;
        pcVar11 = *(code **)(_r_ip_funcs_p + 0x684);
      }
_L89:
      (*pcVar11)(iVar13,param_1,uVar15,pcVar11);
      goto _L6;
    }
    if ((*(byte *)(iVar10 + 0x1c) == 3) && ((sVar8 != 0 && (sVar8 != sVar12)))) {
      uVar18 = (&co_phy_to_rate)[*(byte *)(iVar10 + 0x1d)];
      uVar15 = 3;
      if (sVar8 == 2) {
        uVar15 = 2;
      }
      uVar16 = (**(code **)(_r_ip_funcs_p + 0x338))(param_1,*(code **)(_r_ip_funcs_p + 0x338));
      pcVar11 = *(code **)(_r_ip_funcs_p + 0x37c);
      *(short *)(iVar13 + 8) = (short)uVar16;
      param_3 = (*pcVar11)(param_1,uVar15,uVar18,uVar16,pcVar11);
      if (param_3 == 0) goto _L90;
      *(undefined2 *)(iVar13 + 8) = 0;
      *(undefined2 *)(iVar13 + 0xc) = 0;
    }
    break;
  case 1:
    goto _L12;
  case 2:
    (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x68c));
_L12:
    bVar17 = *(byte *)(iVar13 + 10);
    if (bVar17 != 0) {
      if (((&co_phy_value_to_mask)[*(byte *)(iVar10 + 0x1c)] & bVar17) == 0) {
        if ((bVar17 & 2) == 0) {
          if ((bVar17 & 1) == 0) {
            uVar18 = 4;
          }
          else {
            uVar18 = 1;
          }
        }
        else {
          uVar18 = 2;
        }
        *(undefined1 *)(iVar13 + 0xc) = uVar18;
      }
      else {
        *(undefined1 *)(iVar13 + 0xc) = 0;
      }
    }
    bVar17 = *(byte *)(iVar13 + 0xb);
    if (bVar17 != 0) {
      if (((&co_phy_value_to_mask)[*(byte *)(iVar10 + 0x1d)] & bVar17) == 0) {
        if ((bVar17 & 2) == 0) {
          if ((bVar17 & 1) == 0) {
            uVar18 = 4;
          }
          else {
            uVar18 = 1;
          }
        }
        else {
          uVar18 = 2;
        }
        *(undefined1 *)(iVar13 + 0xd) = uVar18;
      }
      else {
        *(undefined1 *)(iVar13 + 0xd) = 0;
      }
    }
    if (*(char *)(iVar13 + 0xf) != '\0') {
      if (*(byte *)(iVar13 + 0xc) == 0) {
        cVar5 = *(char *)(iVar10 + 0x1c);
      }
      else {
        cVar5 = (&co_phy_mask_to_value)[*(byte *)(iVar13 + 0xc)];
      }
      if (*(byte *)(iVar13 + 0xd) == 0) {
        cVar6 = *(char *)(iVar10 + 0x1d);
      }
      else {
        cVar6 = (&co_phy_mask_to_value)[*(byte *)(iVar13 + 0xd)];
      }
      if (cVar5 != cVar6) {
        *(undefined2 *)(iVar13 + 0xc) = 0;
      }
    }
    bVar9 = true;
    if (*(short *)(iVar13 + 0xc) != 0) {
      if (*(byte *)(iVar13 + 0xc) == 0) {
        bVar17 = *(byte *)(iVar10 + 0x1c);
      }
      else {
        bVar17 = (&co_phy_mask_to_value)[*(byte *)(iVar13 + 0xc)];
      }
      uVar18 = (&co_phy_to_rate)[bVar17];
      if ((bVar17 == 3) && (*(short *)(iVar13 + 0x10) == 2)) {
        uVar18 = 2;
      }
      if (*(byte *)(iVar13 + 0xd) == 0) {
        bVar17 = *(byte *)(iVar10 + 0x1d);
      }
      else {
        bVar17 = (&co_phy_mask_to_value)[*(byte *)(iVar13 + 0xd)];
      }
      uVar7 = (&co_phy_to_rate)[bVar17];
      sVar12 = (**(code **)(_r_ip_funcs_p + 0x338))(param_1,*(code **)(_r_ip_funcs_p + 0x338));
      pcVar11 = *(code **)(_r_ip_funcs_p + 0x37c);
      *(short *)(iVar13 + 8) = *(short *)(iVar10 + 0x10) + 9 + sVar12;
      param_3 = (*pcVar11)(param_1,uVar18,uVar7,pcVar11);
      if (param_3 == 0) {
        bVar9 = false;
        (**(code **)(_r_ip_funcs_p + 0x684))(iVar13,param_1,4,*(code **)(_r_ip_funcs_p + 0x684));
      }
      else {
        *(undefined2 *)(iVar13 + 8) = 0;
        *(undefined2 *)(iVar13 + 0xc) = 0;
        bVar9 = true;
      }
    }
    llc_llcp_phy_upd_ind_pdu_send
              (param_1,*(undefined1 *)(iVar13 + 0xc),*(undefined1 *)(iVar13 + 0xd),
               *(undefined2 *)(iVar13 + 8));
    if (!bVar9) goto _L6;
    break;
  case 3:
    (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x68c));
    if (*(short *)(iVar13 + 0xc) == 0) goto _L88;
    if (*(byte *)(iVar13 + 0xd) == 0) {
      bVar17 = *(byte *)(iVar10 + 0x1c);
    }
    else {
      bVar17 = (&co_phy_mask_to_value)[*(byte *)(iVar13 + 0xd)];
    }
    uVar18 = (&co_phy_to_rate)[bVar17];
    if ((bVar17 == 3) && (*(short *)(iVar13 + 0x10) == 2)) {
      uVar18 = 2;
    }
    if (*(byte *)(iVar13 + 0xc) == 0) {
      bVar17 = *(byte *)(iVar10 + 0x1d);
    }
    else {
      bVar17 = (&co_phy_mask_to_value)[*(byte *)(iVar13 + 0xc)];
    }
    param_3 = (**(code **)(_r_ip_funcs_p + 0x37c))
                        (param_1,uVar18,(&co_phy_to_rate)[bVar17],*(undefined2 *)(iVar13 + 8),
                         *(code **)(_r_ip_funcs_p + 0x37c));
    if (param_3 == 0) {
_L90:
      uVar15 = 4;
      pcVar11 = *(code **)(_r_ip_funcs_p + 0x684);
      goto _L89;
    }
    (**(code **)(_r_plf_funcs_p + 0xc))
              (*(undefined1 *)(iVar13 + 0xd),*(undefined1 *)(iVar13 + 0xc),"llc_phy_upd.c",0x1a3,
               *(code **)(_r_plf_funcs_p + 0xc));
    break;
  case 4:
    if (*(byte *)(iVar13 + 0xc) != 0) {
      if ((*(ushort *)(iVar10 + 0x42) & 1) == 0) {
        *(undefined *)(iVar10 + 0x1d) = (&co_phy_mask_to_value)[*(byte *)(iVar13 + 0xc)];
      }
      else {
        *(undefined *)(iVar10 + 0x1c) = (&co_phy_mask_to_value)[*(byte *)(iVar13 + 0xc)];
      }
    }
    if (*(byte *)(iVar13 + 0xd) != 0) {
      if ((*(ushort *)(iVar10 + 0x42) & 1) == 0) {
        *(undefined *)(iVar10 + 0x1c) = (&co_phy_mask_to_value)[*(byte *)(iVar13 + 0xd)];
      }
      else {
        *(undefined *)(iVar10 + 0x1d) = (&co_phy_mask_to_value)[*(byte *)(iVar13 + 0xd)];
      }
    }
    break;
  default:
    param_3 = 0x1f;
    pcVar11 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar15 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar13,*(code **)(_r_ip_funcs_p + 0x680));
    (*pcVar11)(param_1,uVar15,"llc_phy_upd.c",0x1cb);
    goto _L6;
  }
_L4:
  *(ushort *)(iVar10 + 0x42) = *(ushort *)(iVar10 + 0x42) & 0xffef;
  if ((*(uint *)(iVar13 + 0xc) & 0xffffff) != 0) {
    (**(code **)(_r_ip_funcs_p + 0x644))
              (param_1,param_3,*(undefined1 *)(iVar10 + 0x1c),*(undefined1 *)(iVar10 + 0x1d),
               *(code **)(_r_ip_funcs_p + 0x644));
    (**(code **)(_r_ip_funcs_p + 0x640))(param_1,uVar1,uVar2,*(code **)(_r_ip_funcs_p + 0x640));
    if (*(char *)(iVar13 + 0xe) != '\0') {
      *(byte *)(iVar10 + 0x45) = *(byte *)(iVar10 + 0x45) & 0xbf;
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x690))(param_1,0,*(code **)(_r_ip_funcs_p + 0x690));
_L6:
                    /* WARNING: Could not recover jumptable at 0x000100d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x7e4))(0,param_1,param_2,param_3);
  return;
}

