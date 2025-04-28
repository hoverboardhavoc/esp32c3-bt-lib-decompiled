/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> r_llc_loc_phy_upd_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

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
  short sVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  byte bVar16;
  undefined1 uVar17;
  
  iVar10 = *(int *)(&llc_env + param_1 * 4);
  iVar12 = r_llc_proc_get(0);
  uVar1 = *(undefined1 *)(iVar10 + 0x1c);
  uVar2 = *(undefined1 *)(iVar10 + 0x1d);
  if (param_3 != 0) {
    r_llc_proc_timer_set(param_1,0,0);
_L111:
    r_lld_con_tx_len_update_for_rate(param_1,4);
    goto _L26;
  }
  iVar13 = r_llc_proc_state_get();
  if (iVar13 != param_2) {
    r_llc_proc_state_get(iVar12);
    r_assert_warn(param_2,"llc_phy_upd.c",0x9c);
    return;
  }
  uVar14 = r_llc_proc_state_get(iVar12);
  switch(uVar14) {
  case 0:
    sVar11 = *(short *)(iVar10 + 0x24);
    *(ushort *)(iVar10 + 0x42) = *(ushort *)(iVar10 + 0x42) | 0x10;
    bVar16 = *(byte *)(iVar12 + 0xb);
    *(byte *)(iVar10 + 0x27) = bVar16;
    bVar3 = *(byte *)(iVar12 + 10);
    bVar4 = (&co_phy_value_to_mask)[*(byte *)(iVar10 + 0x1d)];
    *(byte *)(iVar10 + 0x26) = bVar3;
    sVar8 = *(short *)(iVar12 + 0x10);
    *(short *)(iVar10 + 0x24) = sVar8;
    if (((bVar4 & bVar16) == 0) ||
       (((&co_phy_value_to_mask)[*(byte *)(iVar10 + 0x1c)] & bVar3) == 0)) {
      llc_ll_phy_req_pdu_send(param_1);
      r_llc_proc_timer_set(param_1,0,1);
      if ((*(ushort *)(iVar10 + 0x42) & 1) == 0) {
        if ((*(byte *)(iVar12 + 10) & 4) == 0) {
          bVar16 = ~*(byte *)(iVar12 + 10) & 1;
        }
        else {
          bVar16 = 2;
          if (*(short *)(iVar12 + 0x10) != 2) {
            bVar16 = 3;
          }
        }
        r_lld_con_tx_len_update_for_rate(param_1,bVar16);
        uVar14 = 3;
      }
      else {
        uVar14 = 2;
      }
      goto _L112;
    }
    if ((*(byte *)(iVar10 + 0x1c) != 3) || ((sVar8 == 0 || (sVar8 == sVar11)))) goto _L26;
    uVar17 = (&co_phy_to_rate)[*(byte *)(iVar10 + 0x1d)];
    uVar14 = 3;
    if (sVar8 == 2) {
      uVar14 = 2;
    }
    uVar15 = r_lld_con_event_counter_get(param_1);
    *(short *)(iVar12 + 8) = (short)uVar15;
    param_3 = r_lld_con_phys_update(param_1,uVar14,uVar17,uVar15);
    if (param_3 != 0) {
      *(undefined2 *)(iVar12 + 8) = 0;
      *(undefined2 *)(iVar12 + 0xc) = 0;
      goto _L26;
    }
    break;
  case 2:
    r_llc_proc_timer_set(param_1,0,0);
  case 1:
    bVar16 = *(byte *)(iVar12 + 10);
    if (bVar16 != 0) {
      if (((&co_phy_value_to_mask)[*(byte *)(iVar10 + 0x1c)] & bVar16) == 0) {
        if ((bVar16 & 2) == 0) {
          if ((bVar16 & 1) == 0) {
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
    bVar16 = *(byte *)(iVar12 + 0xb);
    if (bVar16 != 0) {
      if (((&co_phy_value_to_mask)[*(byte *)(iVar10 + 0x1d)] & bVar16) == 0) {
        if ((bVar16 & 2) == 0) {
          if ((bVar16 & 1) == 0) {
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
        bVar16 = *(byte *)(iVar10 + 0x1c);
      }
      else {
        bVar16 = (&co_phy_mask_to_value)[*(byte *)(iVar12 + 0xc)];
      }
      uVar17 = (&co_phy_to_rate)[bVar16];
      if ((bVar16 == 3) && (*(short *)(iVar12 + 0x10) == 2)) {
        uVar17 = 2;
      }
      if (*(byte *)(iVar12 + 0xd) == 0) {
        bVar16 = *(byte *)(iVar10 + 0x1d);
      }
      else {
        bVar16 = (&co_phy_mask_to_value)[*(byte *)(iVar12 + 0xd)];
      }
      uVar7 = (&co_phy_to_rate)[bVar16];
      sVar11 = r_lld_con_event_counter_get(param_1);
      *(short *)(iVar12 + 8) = sVar11 + *(short *)(iVar10 + 0x10) + 9;
      param_3 = r_lld_con_phys_update(param_1,uVar17,uVar7);
      if (param_3 == 0) {
        r_llc_proc_state_set(iVar12,param_1,4);
        bVar9 = false;
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
_L26:
    *(ushort *)(iVar10 + 0x42) = *(ushort *)(iVar10 + 0x42) & 0xffef;
    if ((*(uint *)(iVar12 + 0xc) & 0xffffff) != 0) {
      r_llc_hci_le_phy_upd_cmp_evt_send
                (param_1,param_3,*(undefined1 *)(iVar10 + 0x1c),*(undefined1 *)(iVar10 + 0x1d));
      r_llc_dl_chg_check(param_1,uVar1,uVar2);
      if (*(char *)(iVar12 + 0xe) != '\0') {
        *(byte *)(iVar10 + 0x45) = *(byte *)(iVar10 + 0x45) & 0xbf;
      }
    }
    r_llc_proc_unreg(param_1,0);
    return;
  case 3:
    r_llc_proc_timer_set(param_1,0,0);
    if (*(short *)(iVar12 + 0xc) == 0) goto _L111;
    if (*(byte *)(iVar12 + 0xd) == 0) {
      bVar16 = *(byte *)(iVar10 + 0x1c);
    }
    else {
      bVar16 = (&co_phy_mask_to_value)[*(byte *)(iVar12 + 0xd)];
    }
    uVar17 = (&co_phy_to_rate)[bVar16];
    if ((bVar16 == 3) && (*(short *)(iVar12 + 0x10) == 2)) {
      uVar17 = 2;
    }
    if (*(byte *)(iVar12 + 0xc) == 0) {
      bVar16 = *(byte *)(iVar10 + 0x1d);
    }
    else {
      bVar16 = (&co_phy_mask_to_value)[*(byte *)(iVar12 + 0xc)];
    }
    param_3 = r_lld_con_phys_update
                        (param_1,uVar17,(&co_phy_to_rate)[bVar16],*(undefined2 *)(iVar12 + 8));
    if (param_3 != 0) {
      r_assert_param(*(undefined1 *)(iVar12 + 0xd),*(undefined1 *)(iVar12 + 0xc),"llc_phy_upd.c",
                     0x1a2);
      goto _L26;
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
    goto _L26;
  default:
    uVar14 = r_llc_proc_state_get(iVar12);
    r_assert_param(param_1,uVar14,"llc_phy_upd.c",0x1ca);
    return;
  }
  uVar14 = 4;
_L112:
  r_llc_proc_state_set(iVar12,param_1,uVar14);
  return;
}

