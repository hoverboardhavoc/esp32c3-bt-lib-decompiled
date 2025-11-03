/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> r_llc_rem_phy_upd_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_rem_phy_upd_proc_continue(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  byte bVar9;
  undefined1 uVar10;
  
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  iVar5 = r_llc_proc_get(1);
  uVar1 = *(undefined1 *)(iVar4 + 0x1c);
  uVar2 = *(undefined1 *)(iVar4 + 0x1d);
  if (param_3 == 0) {
    iVar6 = r_llc_proc_state_get();
    if (iVar6 != param_2) {
      r_llc_proc_state_get(iVar5);
      r_assert_warn(param_2,"llc_phy_upd.c",0x273);
      return;
    }
    iVar6 = r_llc_proc_state_get(iVar5);
    if (iVar6 != 6) {
      if (iVar6 == 7) {
        if (*(byte *)(iVar5 + 0xc) != 0) {
          *(undefined *)(iVar4 + 0x1d) = (&co_phy_mask_to_value)[*(byte *)(iVar5 + 0xc)];
        }
        if (*(byte *)(iVar5 + 0xd) == 0) {
          param_3 = 0;
        }
        else {
          *(undefined *)(iVar4 + 0x1c) = (&co_phy_mask_to_value)[*(byte *)(iVar5 + 0xd)];
        }
      }
      else {
        if (iVar6 != 5) {
          uVar8 = r_llc_proc_state_get(iVar5);
          r_assert_param(param_1,uVar8,"llc_phy_upd.c",0x2f8);
          return;
        }
        uVar3 = *(ushort *)(iVar4 + 0x42);
        *(ushort *)(iVar4 + 0x42) = uVar3 | 0x10;
        if ((uVar3 & 1) == 0) {
          bVar9 = *(byte *)(iVar4 + 0x26) & *(byte *)(iVar5 + 10);
          if ((bVar9 & 4) == 0) {
            bVar9 = ~bVar9 & 1;
          }
          else {
            bVar9 = 2;
            if (*(short *)(iVar4 + 0x24) != 2) {
              bVar9 = 3;
            }
          }
          r_lld_con_tx_len_update_for_rate(param_1,bVar9);
          r_llc_proc_state_set(iVar5,param_1,6);
          llc_ll_phy_rsp_pdu_send
                    (param_1,*(undefined1 *)(iVar4 + 0x26),*(undefined1 *)(iVar4 + 0x27));
          r_llc_proc_timer_set(param_1,1,1);
          return;
        }
        puVar7 = (undefined4 *)r_ke_msg_alloc(0x10e,param_1 << 8 | 1,0x14);
        *(undefined1 *)(puVar7 + 1) = 9;
        r_llc_proc_state_set(param_1,1);
        *puVar7 = r_llc_loc_phy_upd_proc_err_cb;
        *(byte *)((int)puVar7 + 10) = *(byte *)(iVar4 + 0x26) & *(byte *)(iVar5 + 10);
        *(byte *)((int)puVar7 + 0xb) = *(byte *)(iVar4 + 0x27) & *(byte *)(iVar5 + 0xb);
        *(undefined2 *)(puVar7 + 4) = *(undefined2 *)(iVar4 + 0x24);
        uVar10 = *(undefined1 *)(iVar5 + 0xf);
        *(undefined1 *)((int)puVar7 + 0xe) = 0;
        *(undefined1 *)((int)puVar7 + 0xf) = uVar10;
        r_ke_msg_send(puVar7);
      }
      goto _L137;
    }
    r_llc_proc_timer_set(param_1,1,0);
    if (*(short *)(iVar5 + 0xc) != 0) {
      if (*(byte *)(iVar5 + 0xd) == 0) {
        bVar9 = *(byte *)(iVar4 + 0x1c);
      }
      else {
        bVar9 = (&co_phy_mask_to_value)[*(byte *)(iVar5 + 0xd)];
      }
      uVar10 = (&co_phy_to_rate)[bVar9];
      if ((bVar9 == 3) && (*(short *)(iVar5 + 0x10) == 2)) {
        uVar10 = 2;
      }
      if (*(byte *)(iVar5 + 0xc) == 0) {
        bVar9 = *(byte *)(iVar4 + 0x1d);
      }
      else {
        bVar9 = (&co_phy_mask_to_value)[*(byte *)(iVar5 + 0xc)];
      }
      param_3 = r_lld_con_phys_update
                          (param_1,uVar10,(&co_phy_to_rate)[bVar9],*(undefined2 *)(iVar5 + 8));
      if (param_3 == 0) {
        r_llc_proc_state_set(iVar5,param_1,7);
        return;
      }
      r_assert_param(*(undefined1 *)(iVar5 + 0xd),*(undefined1 *)(iVar5 + 0xc),"llc_phy_upd.c",0x2df
                    );
      goto _L137;
    }
  }
  r_lld_con_tx_len_update_for_rate(param_1,4);
_L137:
  if ((*(ushort *)(iVar4 + 0x42) & 1) == 0) {
    *(ushort *)(iVar4 + 0x42) = *(ushort *)(iVar4 + 0x42) & 0xffef;
    if (*(short *)(iVar5 + 0xc) != 0) {
      r_llc_hci_le_phy_upd_cmp_evt_send
                (param_1,param_3,*(undefined1 *)(iVar4 + 0x1c),*(undefined1 *)(iVar4 + 0x1d));
      r_llc_dl_chg_check(param_1,uVar1,uVar2);
    }
  }
  r_llc_proc_unreg(param_1,1);
  return;
}

