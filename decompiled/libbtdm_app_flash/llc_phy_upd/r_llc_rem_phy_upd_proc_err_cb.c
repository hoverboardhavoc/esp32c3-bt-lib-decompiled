/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> r_llc_rem_phy_upd_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_rem_phy_upd_proc_err_cb(int param_1,int param_2,byte *param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  byte bVar8;
  undefined1 uVar9;
  uint uVar10;
  int iVar11;
  
  if (param_2 != 0) {
    if ((param_2 - 1U & 0xff) < 3) {
      return;
    }
    r_assert_param("llc_phy_upd.c",0x3c2);
    return;
  }
  uVar10 = (uint)*param_3;
  iVar11 = *(int *)(&llc_env + param_1 * 4);
  r_llc_proc_get(1);
  iVar7 = r_llc_proc_state_get();
  if (iVar7 == 5) {
    r_llm_get_preferred_phys(iVar11 + 0x26,iVar11 + 0x27);
  }
  iVar7 = *(int *)(&llc_env + param_1 * 4);
  iVar11 = r_llc_proc_get(1);
  uVar1 = *(undefined1 *)(iVar7 + 0x1c);
  uVar2 = *(undefined1 *)(iVar7 + 0x1d);
  if (uVar10 == 0) {
    iVar4 = r_llc_proc_state_get();
    if (iVar4 != 0) {
      r_llc_proc_state_get(iVar11);
      r_assert_warn(0,"llc_phy_upd.c",0x26e);
      return;
    }
    iVar4 = r_llc_proc_state_get(iVar11);
    if (iVar4 != 6) {
      if (iVar4 == 7) {
        if (*(byte *)(iVar11 + 0xc) != 0) {
          *(undefined *)(iVar7 + 0x1d) = (&co_phy_mask_to_value)[*(byte *)(iVar11 + 0xc)];
        }
        if (*(byte *)(iVar11 + 0xd) != 0) {
          *(undefined *)(iVar7 + 0x1c) = (&co_phy_mask_to_value)[*(byte *)(iVar11 + 0xd)];
        }
      }
      else {
        if (iVar4 != 5) {
          uVar6 = r_llc_proc_state_get(iVar11);
          r_assert_param(param_1,uVar6,"llc_phy_upd.c",0x2f3);
          return;
        }
        uVar3 = *(ushort *)(iVar7 + 0x42);
        *(ushort *)(iVar7 + 0x42) = uVar3 | 0x10;
        if ((uVar3 & 1) == 0) {
          bVar8 = *(byte *)(iVar7 + 0x26) & *(byte *)(iVar11 + 10);
          if ((bVar8 & 4) == 0) {
            bVar8 = ~bVar8 & 1;
          }
          else {
            bVar8 = 3;
            if (*(short *)(iVar7 + 0x24) == 2) {
              bVar8 = 2;
            }
          }
          r_lld_con_tx_len_update_for_rate(param_1,bVar8);
          r_llc_proc_state_set(iVar11,param_1,6);
          llc_ll_phy_rsp_pdu_send
                    (param_1,*(undefined1 *)(iVar7 + 0x26),*(undefined1 *)(iVar7 + 0x27));
          r_llc_proc_timer_set(param_1,1);
          return;
        }
        puVar5 = (undefined4 *)r_ke_msg_alloc(0x10e,param_1 << 8 | 1,0x14);
        *(undefined1 *)(puVar5 + 1) = 9;
        r_llc_proc_state_set(param_1,1);
        *puVar5 = r_llc_loc_phy_upd_proc_err_cb;
        *(byte *)((int)puVar5 + 10) = *(byte *)(iVar7 + 0x26) & *(byte *)(iVar11 + 10);
        *(byte *)((int)puVar5 + 0xb) = *(byte *)(iVar7 + 0x27) & *(byte *)(iVar11 + 0xb);
        *(undefined2 *)(puVar5 + 4) = *(undefined2 *)(iVar7 + 0x24);
        uVar9 = *(undefined1 *)(iVar11 + 0xf);
        *(undefined1 *)((int)puVar5 + 0xe) = 0;
        *(undefined1 *)((int)puVar5 + 0xf) = uVar9;
        r_ke_msg_send(puVar5);
      }
      goto _L136;
    }
    r_llc_proc_timer_set(param_1,1,0);
    if (*(short *)(iVar11 + 0xc) != 0) {
      if (*(byte *)(iVar11 + 0xd) == 0) {
        bVar8 = *(byte *)(iVar7 + 0x1c);
      }
      else {
        bVar8 = (&co_phy_mask_to_value)[*(byte *)(iVar11 + 0xd)];
      }
      uVar9 = (&co_phy_to_rate)[bVar8];
      if ((bVar8 == 3) && (*(short *)(iVar11 + 0x10) == 2)) {
        uVar9 = 2;
      }
      if (*(byte *)(iVar11 + 0xc) == 0) {
        bVar8 = *(byte *)(iVar7 + 0x1d);
      }
      else {
        bVar8 = (&co_phy_mask_to_value)[*(byte *)(iVar11 + 0xc)];
      }
      uVar10 = r_lld_con_phys_update
                         (param_1,uVar9,(&co_phy_to_rate)[bVar8],*(undefined2 *)(iVar11 + 8));
      if (uVar10 == 0) {
        r_llc_proc_state_set(iVar11,param_1,7);
        return;
      }
      r_assert_param(*(undefined1 *)(iVar11 + 0xd),*(undefined1 *)(iVar11 + 0xc),"llc_phy_upd.c",
                     0x2da);
      goto _L136;
    }
  }
  r_lld_con_tx_len_update_for_rate(param_1,4);
_L136:
  if (((*(ushort *)(iVar7 + 0x42) & 1) == 0) &&
     (*(ushort *)(iVar7 + 0x42) = *(ushort *)(iVar7 + 0x42) & 0xffef, *(short *)(iVar11 + 0xc) != 0)
     ) {
    r_llc_hci_le_phy_upd_cmp_evt_send
              (param_1,uVar10,*(undefined1 *)(iVar7 + 0x1c),*(undefined1 *)(iVar7 + 0x1d));
    r_llc_dl_chg_check(param_1,uVar1,uVar2);
  }
  r_llc_proc_unreg(param_1,1);
  return;
}

