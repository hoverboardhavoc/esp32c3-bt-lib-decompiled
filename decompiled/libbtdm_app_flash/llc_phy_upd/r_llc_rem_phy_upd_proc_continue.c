/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> r_llc_rem_phy_upd_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_rem_phy_upd_proc_continue(uint param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  byte bVar8;
  undefined1 uVar9;
  int iVar10;
  
  iVar10 = *(int *)(&llc_env + param_1 * 4);
  iVar4 = r_llc_proc_get(1);
  uVar1 = *(undefined1 *)(iVar10 + 0x1c);
  uVar2 = *(undefined1 *)(iVar10 + 0x1d);
  if (param_3 == 0) {
    iVar5 = r_llc_proc_state_get();
    if (iVar5 != param_2) {
      iVar10 = r_llc_proc_state_get(iVar4);
      r_ble_log_internal_x1(0x804f00bc,param_2 << 0x10 | param_1 | iVar10 << 8);
      r_llc_proc_state_get(iVar4);
      r_assert_warn(param_2,"llc_phy_upd.c",0x279);
      return;
    }
    iVar5 = r_llc_proc_state_get(iVar4);
    if (iVar5 != 6) {
      if (iVar5 == 7) {
        if (*(byte *)(iVar4 + 0xc) != 0) {
          *(undefined *)(iVar10 + 0x1d) = (&co_phy_mask_to_value)[*(byte *)(iVar4 + 0xc)];
        }
        if (*(byte *)(iVar4 + 0xd) == 0) {
          param_3 = 0;
        }
        else {
          *(undefined *)(iVar10 + 0x1c) = (&co_phy_mask_to_value)[*(byte *)(iVar4 + 0xd)];
        }
      }
      else {
        if (iVar5 != 5) {
          uVar7 = r_llc_proc_state_get(iVar4);
          r_assert_param(param_1,uVar7,"llc_phy_upd.c",0x300);
          return;
        }
        uVar3 = *(ushort *)(iVar10 + 0x42);
        *(ushort *)(iVar10 + 0x42) = uVar3 | 0x10;
        if ((uVar3 & 1) == 0) {
          bVar8 = *(byte *)(iVar10 + 0x26) & *(byte *)(iVar4 + 10);
          if ((bVar8 & 4) == 0) {
            bVar8 = ~bVar8 & 1;
          }
          else {
            bVar8 = 2;
            if (*(short *)(iVar10 + 0x24) != 2) {
              bVar8 = 3;
            }
          }
          r_lld_con_tx_len_update_for_rate(param_1,bVar8);
          r_llc_proc_state_set(iVar4,param_1,6);
          llc_ll_phy_rsp_pdu_send
                    (param_1,*(undefined1 *)(iVar10 + 0x26),*(undefined1 *)(iVar10 + 0x27));
          r_llc_proc_timer_set(param_1,1,1);
          return;
        }
        puVar6 = (undefined4 *)r_ke_msg_alloc(0x10e,param_1 << 8 | 1,0x14);
        *(undefined1 *)(puVar6 + 1) = 9;
        r_llc_proc_state_set(param_1,1);
        *puVar6 = r_llc_loc_phy_upd_proc_err_cb;
        *(byte *)((int)puVar6 + 10) = *(byte *)(iVar10 + 0x26) & *(byte *)(iVar4 + 10);
        *(byte *)((int)puVar6 + 0xb) = *(byte *)(iVar10 + 0x27) & *(byte *)(iVar4 + 0xb);
        *(undefined2 *)(puVar6 + 4) = *(undefined2 *)(iVar10 + 0x24);
        uVar9 = *(undefined1 *)(iVar4 + 0xf);
        *(undefined1 *)((int)puVar6 + 0xe) = 0;
        *(undefined1 *)((int)puVar6 + 0xf) = uVar9;
        r_ke_msg_send(puVar6);
      }
      goto _L137;
    }
    r_llc_proc_timer_set(param_1,1,0);
    if (*(short *)(iVar4 + 0xc) != 0) {
      if (*(byte *)(iVar4 + 0xd) == 0) {
        bVar8 = *(byte *)(iVar10 + 0x1c);
      }
      else {
        bVar8 = (&co_phy_mask_to_value)[*(byte *)(iVar4 + 0xd)];
      }
      uVar9 = (&co_phy_to_rate)[bVar8];
      if ((bVar8 == 3) && (*(short *)(iVar4 + 0x10) == 2)) {
        uVar9 = 2;
      }
      if (*(byte *)(iVar4 + 0xc) == 0) {
        bVar8 = *(byte *)(iVar10 + 0x1d);
      }
      else {
        bVar8 = (&co_phy_mask_to_value)[*(byte *)(iVar4 + 0xc)];
      }
      param_3 = r_lld_con_phys_update
                          (param_1,uVar9,(&co_phy_to_rate)[bVar8],*(undefined2 *)(iVar4 + 8));
      if (param_3 == 0) {
        r_llc_proc_state_set(iVar4,param_1,7);
        return;
      }
      r_ble_log_internal_x1
                (0x804f00bd,
                 param_3 << 8 |
                 (uint)*(byte *)(iVar4 + 0xd) << 0x10 | (uint)*(byte *)(iVar4 + 0xc) << 0x18 |
                 param_1);
      r_assert_param(*(undefined1 *)(iVar4 + 0xd),*(undefined1 *)(iVar4 + 0xc),"llc_phy_upd.c",0x2e7
                    );
      goto _L137;
    }
  }
  r_lld_con_tx_len_update_for_rate(param_1,4);
_L137:
  if ((*(ushort *)(iVar10 + 0x42) & 1) == 0) {
    *(ushort *)(iVar10 + 0x42) = *(ushort *)(iVar10 + 0x42) & 0xffef;
    if (*(short *)(iVar4 + 0xc) != 0) {
      r_llc_hci_le_phy_upd_cmp_evt_send
                (param_1,param_3,*(undefined1 *)(iVar10 + 0x1c),*(undefined1 *)(iVar10 + 0x1d));
      r_llc_dl_chg_check(param_1,uVar1,uVar2);
    }
  }
  r_llc_proc_unreg(param_1,1);
  return;
}

