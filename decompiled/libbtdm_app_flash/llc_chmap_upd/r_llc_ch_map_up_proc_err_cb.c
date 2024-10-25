/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_chmap_upd.o -> r_llc_ch_map_up_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_ch_map_up_proc_err_cb(int param_1,uint param_2,undefined1 *param_3)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  void *pvVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  byte abStack_28 [16];
  
  if (param_2 != 0) {
    if (param_2 < 4) {
      return;
    }
    r_assert_param("llc_chmap_upd.c",0x166);
    return;
  }
  uVar2 = *param_3;
  iVar10 = r_llc_proc_id_get();
  if (iVar10 != 6) {
    iVar10 = r_llc_proc_id_get(param_1,1);
    if (iVar10 != 6) {
      return;
    }
    iVar6 = *(int *)(&llc_env + param_1 * 4);
    iVar10 = r_llc_proc_get(1,uVar2);
    iVar5 = r_llc_proc_state_get();
    if (iVar5 == 5) {
      iVar5 = r_llc_proc_state_get(iVar10);
      if (iVar5 == 3) {
        uVar3 = *(undefined2 *)(iVar10 + 0xe);
        *(ushort *)(iVar6 + 0x42) = *(ushort *)(iVar6 + 0x42) | 0x10;
        iVar5 = r_lld_con_ch_map_update(param_1,iVar10 + 8,uVar3);
        if (iVar5 == 0) {
          r_llc_proc_state_set(iVar10,param_1,4);
          return;
        }
      }
      else {
        if (iVar5 != 4) {
          uVar7 = r_llc_proc_state_get(iVar10);
          r_assert_param(param_1,uVar7,"llc_chmap_upd.c",0x11d);
          return;
        }
        memcpy((void *)(iVar6 + 8),(void *)(iVar10 + 8),5);
      }
    }
    *(ushort *)(iVar6 + 0x42) = *(ushort *)(iVar6 + 0x42) & 0xffef;
    r_llc_proc_unreg(param_1,1);
    return;
  }
  iVar10 = *(int *)(&llc_env + param_1 * 4);
  iVar5 = r_llc_proc_get(0);
  iVar6 = r_llc_proc_state_get();
  if (iVar6 == 2) {
    iVar6 = r_llc_proc_state_get(iVar5);
    if (iVar6 == 0) {
      pvVar8 = (void *)r_llm_master_ch_map_get();
      memcpy(abStack_28,pvVar8,5);
      uVar9 = r_co_nb_good_le_channels(abStack_28);
      bVar1 = *(byte *)(iVar10 + 0x1f);
      if (uVar9 < bVar1) {
        uVar11 = 0;
        do {
          if (((int)(uint)abStack_28[(int)uVar11 >> 3] >> (uVar11 & 7) & 1U) == 0) {
            abStack_28[(int)uVar11 >> 3] = (byte)(1 << (uVar11 & 7)) | abStack_28[(int)uVar11 >> 3];
            uVar9 = uVar9 + 1 & 0xff;
            if (bVar1 <= uVar9) break;
          }
          uVar11 = uVar11 + 1;
        } while (uVar11 != 0x25);
      }
      iVar6 = memcmp((void *)(iVar10 + 8),abStack_28,5);
      if (iVar6 != 0) {
        pvVar8 = (void *)(iVar5 + 8);
        *(ushort *)(iVar10 + 0x42) = *(ushort *)(iVar10 + 0x42) | 0x10;
        sVar4 = r_lld_con_event_counter_get(param_1);
        sVar4 = *(short *)(iVar10 + 0x10) + 9 + sVar4;
        *(short *)(iVar5 + 0xe) = sVar4;
        memcpy(pvVar8,abStack_28,5);
        iVar6 = r_lld_con_ch_map_update(param_1,pvVar8,sVar4);
        if (iVar6 == 0) {
          llc_llcp_ch_map_update_ind_pdu_send(param_1,*(undefined2 *)(iVar5 + 0xe),pvVar8);
          r_llc_proc_state_set(iVar5,param_1,1);
          return;
        }
      }
    }
    else {
      if (iVar6 != 1) {
        uVar7 = r_llc_proc_state_get(iVar5);
        r_assert_param(param_1,uVar7,"llc_chmap_upd.c",0xcc);
        return;
      }
      memcpy((void *)(iVar10 + 8),(void *)(iVar5 + 8),5);
    }
  }
  *(ushort *)(iVar10 + 0x42) = *(ushort *)(iVar10 + 0x42) & 0xffef;
  r_llc_proc_unreg(param_1,0);
  *(ushort *)(iVar10 + 0x42) = *(ushort *)(iVar10 + 0x42) & 0xfeff;
  return;
}

