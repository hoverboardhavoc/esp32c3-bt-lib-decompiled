/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> r_llc_rem_phy_upd_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_rem_phy_upd_proc_err_cb(int param_1,uint param_2,byte *param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  byte bVar9;
  undefined1 uVar10;
  uint uVar11;
  
  if (param_2 != 0) {
    if (3 < param_2) {
      r_assert_param("llc_phy_upd.c",0x3c2);
      return;
    }
    return;
  }
  uVar11 = (uint)*param_3;
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  r_llc_proc_get(1);
  iVar8 = r_llc_proc_state_get();
  if (iVar8 == 5) {
    r_llm_get_preferred_phys(iVar4 + 0x26,iVar4 + 0x27);
  }
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  iVar8 = r_llc_proc_get(1);
  uVar1 = *(undefined1 *)(iVar4 + 0x1c);
  uVar2 = *(undefined1 *)(iVar4 + 0x1d);
  if (uVar11 == 0) {
    iVar5 = r_llc_proc_state_get();
    if (iVar5 != 0) {
      r_llc_proc_state_get(iVar8);
      r_assert_warn(0,"llc_phy_upd.c",0x26e);
      return;
    }
    iVar5 = r_llc_proc_state_get(iVar8);
    if (iVar5 != 6) {
      if (iVar5 == 7) {
        if (*(byte *)(iVar8 + 0xc) != 0) {
          *(undefined *)(iVar4 + 0x1d) = (&co_phy_mask_to_value)[*(byte *)(iVar8 + 0xc)];
        }
        if (*(byte *)(iVar8 + 0xd) == 0) {
          uVar11 = 0;
        }
        else {
          *(undefined *)(iVar4 + 0x1c) = (&co_phy_mask_to_value)[*(byte *)(iVar8 + 0xd)];
        }
      }
      else {
        if (iVar5 != 5) {
          uVar7 = r_llc_proc_state_get(iVar8);
          r_assert_param(param_1,uVar7,"llc_phy_upd.c",0x2f3);
          return;
        }
        uVar3 = *(ushort *)(iVar4 + 0x42);
        *(ushort *)(iVar4 + 0x42) = uVar3 | 0x10;
        if ((uVar3 & 1) == 0) {
          bVar9 = *(byte *)(iVar4 + 0x26) & *(byte *)(iVar8 + 10);
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
          r_llc_proc_state_set(iVar8,param_1,6);
          llc_ll_phy_rsp_pdu_send
                    (param_1,*(undefined1 *)(iVar4 + 0x26),*(undefined1 *)(iVar4 + 0x27));
          r_llc_proc_timer_set(param_1,1,1);
          return;
        }
        puVar6 = (undefined4 *)r_ke_msg_alloc(0x10e,param_1 << 8 | 1,0x14);
        *(undefined1 *)(puVar6 + 1) = 9;
        r_llc_proc_state_set(param_1,1);
        *puVar6 = r_llc_loc_phy_upd_proc_err_cb;
        *(byte *)((int)puVar6 + 10) = *(byte *)(iVar4 + 0x26) & *(byte *)(iVar8 + 10);
        *(byte *)((int)puVar6 + 0xb) = *(byte *)(iVar4 + 0x27) & *(byte *)(iVar8 + 0xb);
        *(undefined2 *)(puVar6 + 4) = *(undefined2 *)(iVar4 + 0x24);
        uVar10 = *(undefined1 *)(iVar8 + 0xf);
        *(undefined1 *)((int)puVar6 + 0xe) = 0;
        *(undefined1 *)((int)puVar6 + 0xf) = uVar10;
        r_ke_msg_send(puVar6);
      }
      goto _L137;
    }
    r_llc_proc_timer_set(param_1,1,0);
    if (*(short *)(iVar8 + 0xc) != 0) {
      if (*(byte *)(iVar8 + 0xd) == 0) {
        bVar9 = *(byte *)(iVar4 + 0x1c);
      }
      else {
        bVar9 = (&co_phy_mask_to_value)[*(byte *)(iVar8 + 0xd)];
      }
      uVar10 = (&co_phy_to_rate)[bVar9];
      if ((bVar9 == 3) && (*(short *)(iVar8 + 0x10) == 2)) {
        uVar10 = 2;
      }
      if (*(byte *)(iVar8 + 0xc) == 0) {
        bVar9 = *(byte *)(iVar4 + 0x1d);
      }
      else {
        bVar9 = (&co_phy_mask_to_value)[*(byte *)(iVar8 + 0xc)];
      }
      uVar11 = r_lld_con_phys_update
                         (param_1,uVar10,(&co_phy_to_rate)[bVar9],*(undefined2 *)(iVar8 + 8));
      if (uVar11 == 0) {
        r_llc_proc_state_set(iVar8,param_1,7);
        return;
      }
      r_assert_param(*(undefined1 *)(iVar8 + 0xd),*(undefined1 *)(iVar8 + 0xc),"llc_phy_upd.c",0x2da
                    );
      goto _L137;
    }
  }
  r_lld_con_tx_len_update_for_rate(param_1,4);
_L137:
  if (((*(ushort *)(iVar4 + 0x42) & 1) == 0) &&
     (*(ushort *)(iVar4 + 0x42) = *(ushort *)(iVar4 + 0x42) & 0xffef, *(short *)(iVar8 + 0xc) != 0))
  {
    r_llc_hci_le_phy_upd_cmp_evt_send
              (param_1,uVar11,*(undefined1 *)(iVar4 + 0x1c),*(undefined1 *)(iVar4 + 0x1d));
    r_llc_dl_chg_check(param_1,uVar1,uVar2);
  }
  r_llc_proc_unreg(param_1,1);
  return;
}

