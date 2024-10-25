/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> r_llc_loc_phy_upd_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_loc_phy_upd_proc_err_cb(uint param_1,int param_2,byte *param_3)

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
  short sVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int iVar15;
  byte bVar16;
  uint uVar17;
  undefined1 uVar18;
  
  if (param_2 == 1) {
    if (param_3[1] != 0x16) {
      return;
    }
    uVar17 = 0x19;
_L125:
    iVar15 = r_sdk_config_get_opts();
    if ((param_1 < *(byte *)(iVar15 + 0xd)) &&
       (iVar15 = *(int *)(&llc_env + param_1 * 4), iVar15 != 0)) {
      *(byte *)(iVar15 + 0x31) = *(byte *)(iVar15 + 0x31) & 0xfe;
    }
  }
  else {
    if (param_2 == 0) {
      uVar17 = (uint)*param_3;
    }
    else if (param_2 == 2) {
      uVar17 = (uint)param_3[1];
    }
    else {
      if (param_2 != 3) {
        return;
      }
      if (param_3[1] != 0x16) {
        return;
      }
      uVar17 = (uint)param_3[2];
    }
    if (uVar17 == 0) {
      return;
    }
    if ((uVar17 - 0x19 & 0xff) < 2) goto _L125;
  }
  iVar15 = *(int *)(&llc_env + param_1 * 4);
  iVar11 = r_llc_proc_get(0);
  uVar1 = *(undefined1 *)(iVar15 + 0x1c);
  uVar2 = *(undefined1 *)(iVar15 + 0x1d);
  if (uVar17 == 0) {
    iVar12 = r_llc_proc_state_get();
    if (iVar12 != 0) {
      r_llc_proc_state_get(iVar11);
      r_assert_warn(0,"llc_phy_upd.c",0x9c);
      return;
    }
    uVar13 = r_llc_proc_state_get(iVar11);
    switch(uVar13) {
    case 0:
      sVar10 = *(short *)(iVar15 + 0x24);
      *(ushort *)(iVar15 + 0x42) = *(ushort *)(iVar15 + 0x42) | 0x10;
      bVar16 = *(byte *)(iVar11 + 0xb);
      *(byte *)(iVar15 + 0x27) = bVar16;
      bVar3 = *(byte *)(iVar11 + 10);
      bVar4 = (&co_phy_value_to_mask)[*(byte *)(iVar15 + 0x1d)];
      *(byte *)(iVar15 + 0x26) = bVar3;
      sVar8 = *(short *)(iVar11 + 0x10);
      *(short *)(iVar15 + 0x24) = sVar8;
      if (((bVar4 & bVar16) == 0) ||
         (((&co_phy_value_to_mask)[*(byte *)(iVar15 + 0x1c)] & bVar3) == 0)) {
        llc_ll_phy_req_pdu_send(param_1);
        r_llc_proc_timer_set(param_1,0,1);
        if ((*(ushort *)(iVar15 + 0x42) & 1) == 0) {
          if ((*(byte *)(iVar11 + 10) & 4) == 0) {
            bVar16 = ~*(byte *)(iVar11 + 10) & 1;
          }
          else {
            bVar16 = 2;
            if (*(short *)(iVar11 + 0x10) != 2) {
              bVar16 = 3;
            }
          }
          r_lld_con_tx_len_update_for_rate(param_1,bVar16);
          uVar13 = 3;
        }
        else {
          uVar13 = 2;
        }
        goto _L116;
      }
      if (((*(byte *)(iVar15 + 0x1c) != 3) || (sVar8 == 0)) || (sVar8 == sVar10)) goto _L30;
      uVar18 = (&co_phy_to_rate)[*(byte *)(iVar15 + 0x1d)];
      uVar13 = 3;
      if (sVar8 == 2) {
        uVar13 = 2;
      }
      uVar14 = r_lld_con_event_counter_get(param_1);
      *(short *)(iVar11 + 8) = (short)uVar14;
      uVar17 = r_lld_con_phys_update(param_1,uVar13,uVar18,uVar14);
      if (uVar17 != 0) {
        *(undefined2 *)(iVar11 + 8) = 0;
        *(undefined2 *)(iVar11 + 0xc) = 0;
        goto _L30;
      }
      break;
    case 2:
      r_llc_proc_timer_set(param_1,0,0);
    case 1:
      bVar16 = *(byte *)(iVar11 + 10);
      if (bVar16 != 0) {
        if (((&co_phy_value_to_mask)[*(byte *)(iVar15 + 0x1c)] & bVar16) == 0) {
          if ((bVar16 & 2) == 0) {
            if ((bVar16 & 1) == 0) {
              uVar18 = 4;
            }
            else {
              uVar18 = 1;
            }
          }
          else {
            uVar18 = 2;
          }
          *(undefined1 *)(iVar11 + 0xc) = uVar18;
        }
        else {
          *(undefined1 *)(iVar11 + 0xc) = 0;
        }
      }
      bVar16 = *(byte *)(iVar11 + 0xb);
      if (bVar16 != 0) {
        if (((&co_phy_value_to_mask)[*(byte *)(iVar15 + 0x1d)] & bVar16) == 0) {
          if ((bVar16 & 2) == 0) {
            if ((bVar16 & 1) == 0) {
              uVar18 = 4;
            }
            else {
              uVar18 = 1;
            }
          }
          else {
            uVar18 = 2;
          }
          *(undefined1 *)(iVar11 + 0xd) = uVar18;
        }
        else {
          *(undefined1 *)(iVar11 + 0xd) = 0;
        }
      }
      if (*(char *)(iVar11 + 0xf) != '\0') {
        if (*(byte *)(iVar11 + 0xc) == 0) {
          cVar5 = *(char *)(iVar15 + 0x1c);
        }
        else {
          cVar5 = (&co_phy_mask_to_value)[*(byte *)(iVar11 + 0xc)];
        }
        if (*(byte *)(iVar11 + 0xd) == 0) {
          cVar6 = *(char *)(iVar15 + 0x1d);
        }
        else {
          cVar6 = (&co_phy_mask_to_value)[*(byte *)(iVar11 + 0xd)];
        }
        if (cVar5 != cVar6) {
          *(undefined2 *)(iVar11 + 0xc) = 0;
        }
      }
      bVar9 = true;
      if (*(short *)(iVar11 + 0xc) != 0) {
        if (*(byte *)(iVar11 + 0xc) == 0) {
          bVar16 = *(byte *)(iVar15 + 0x1c);
        }
        else {
          bVar16 = (&co_phy_mask_to_value)[*(byte *)(iVar11 + 0xc)];
        }
        uVar18 = (&co_phy_to_rate)[bVar16];
        if ((bVar16 == 3) && (*(short *)(iVar11 + 0x10) == 2)) {
          uVar18 = 2;
        }
        if (*(byte *)(iVar11 + 0xd) == 0) {
          bVar16 = *(byte *)(iVar15 + 0x1d);
        }
        else {
          bVar16 = (&co_phy_mask_to_value)[*(byte *)(iVar11 + 0xd)];
        }
        uVar7 = (&co_phy_to_rate)[bVar16];
        sVar10 = r_lld_con_event_counter_get(param_1);
        *(short *)(iVar11 + 8) = *(short *)(iVar15 + 0x10) + 9 + sVar10;
        uVar17 = r_lld_con_phys_update(param_1,uVar18,uVar7);
        if (uVar17 == 0) {
          r_llc_proc_state_set(iVar11,param_1,4);
          bVar9 = false;
        }
        else {
          *(undefined2 *)(iVar11 + 8) = 0;
          *(undefined2 *)(iVar11 + 0xc) = 0;
          bVar9 = true;
        }
      }
      llc_llcp_phy_upd_ind_pdu_send
                (param_1,*(undefined1 *)(iVar11 + 0xc),*(undefined1 *)(iVar11 + 0xd),
                 *(undefined2 *)(iVar11 + 8));
      if (!bVar9) {
        return;
      }
_L30:
      *(ushort *)(iVar15 + 0x42) = *(ushort *)(iVar15 + 0x42) & 0xffef;
      if ((*(uint *)(iVar11 + 0xc) & 0xffffff) != 0) {
        r_llc_hci_le_phy_upd_cmp_evt_send
                  (param_1,uVar17,*(undefined1 *)(iVar15 + 0x1c),*(undefined1 *)(iVar15 + 0x1d));
        r_llc_dl_chg_check(param_1,uVar1,uVar2);
        if (*(char *)(iVar11 + 0xe) != '\0') {
          *(byte *)(iVar15 + 0x45) = *(byte *)(iVar15 + 0x45) & 0xbf;
        }
      }
      r_llc_proc_unreg(param_1,0);
      return;
    case 3:
      r_llc_proc_timer_set(param_1,0,0);
      if (*(short *)(iVar11 + 0xc) == 0) goto _L115;
      if (*(byte *)(iVar11 + 0xd) == 0) {
        bVar16 = *(byte *)(iVar15 + 0x1c);
      }
      else {
        bVar16 = (&co_phy_mask_to_value)[*(byte *)(iVar11 + 0xd)];
      }
      uVar18 = (&co_phy_to_rate)[bVar16];
      if ((bVar16 == 3) && (*(short *)(iVar11 + 0x10) == 2)) {
        uVar18 = 2;
      }
      if (*(byte *)(iVar11 + 0xc) == 0) {
        bVar16 = *(byte *)(iVar15 + 0x1d);
      }
      else {
        bVar16 = (&co_phy_mask_to_value)[*(byte *)(iVar11 + 0xc)];
      }
      uVar17 = r_lld_con_phys_update
                         (param_1,uVar18,(&co_phy_to_rate)[bVar16],*(undefined2 *)(iVar11 + 8));
      if (uVar17 != 0) {
        r_assert_param(*(undefined1 *)(iVar11 + 0xd),*(undefined1 *)(iVar11 + 0xc),"llc_phy_upd.c",
                       0x1a2);
        goto _L30;
      }
      break;
    case 4:
      if (*(byte *)(iVar11 + 0xc) != 0) {
        if ((*(ushort *)(iVar15 + 0x42) & 1) == 0) {
          *(undefined *)(iVar15 + 0x1d) = (&co_phy_mask_to_value)[*(byte *)(iVar11 + 0xc)];
        }
        else {
          *(undefined *)(iVar15 + 0x1c) = (&co_phy_mask_to_value)[*(byte *)(iVar11 + 0xc)];
        }
      }
      if (*(byte *)(iVar11 + 0xd) != 0) {
        if ((*(ushort *)(iVar15 + 0x42) & 1) == 0) {
          *(undefined *)(iVar15 + 0x1c) = (&co_phy_mask_to_value)[*(byte *)(iVar11 + 0xd)];
        }
        else {
          *(undefined *)(iVar15 + 0x1d) = (&co_phy_mask_to_value)[*(byte *)(iVar11 + 0xd)];
        }
      }
      goto _L30;
    default:
      uVar13 = r_llc_proc_state_get(iVar11);
      r_assert_param(param_1,uVar13,"llc_phy_upd.c",0x1ca);
      return;
    }
    uVar13 = 4;
_L116:
    r_llc_proc_state_set(iVar11,param_1,uVar13);
    return;
  }
  r_llc_proc_timer_set(param_1,0,0);
_L115:
  r_lld_con_tx_len_update_for_rate(param_1,4);
  goto _L30;
}

