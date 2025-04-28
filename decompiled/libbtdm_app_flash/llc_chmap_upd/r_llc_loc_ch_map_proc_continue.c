/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_chmap_upd.o -> r_llc_loc_ch_map_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_loc_ch_map_proc_continue(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvVar7;
  uint uVar8;
  uint uVar9;
  byte abStack_28 [16];
  
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  iVar4 = r_llc_proc_get(0);
  iVar5 = r_llc_proc_state_get();
  if (iVar5 == param_2) {
    iVar5 = r_llc_proc_state_get(iVar4);
    if (iVar5 == 0) {
      pvVar7 = (void *)r_llm_master_ch_map_get();
      memcpy(abStack_28,pvVar7,5);
      uVar8 = r_co_nb_good_le_channels(abStack_28);
      bVar1 = *(byte *)(iVar2 + 0x1f);
      if (uVar8 < bVar1) {
        uVar9 = 0;
        do {
          if (((int)(uint)abStack_28[(int)uVar9 >> 3] >> (uVar9 & 7) & 1U) == 0) {
            abStack_28[(int)uVar9 >> 3] = abStack_28[(int)uVar9 >> 3] | (byte)(1 << (uVar9 & 7));
            uVar8 = uVar8 + 1 & 0xff;
            if (bVar1 <= uVar8) break;
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 != 0x25);
      }
      iVar5 = memcmp((void *)(iVar2 + 8),abStack_28,5);
      if (iVar5 != 0) {
        *(ushort *)(iVar2 + 0x42) = *(ushort *)(iVar2 + 0x42) | 0x10;
        sVar3 = r_lld_con_event_counter_get(param_1);
        pvVar7 = (void *)(iVar4 + 8);
        sVar3 = sVar3 + *(short *)(iVar2 + 0x10) + 9;
        *(short *)(iVar4 + 0xe) = sVar3;
        memcpy(pvVar7,abStack_28,5);
        iVar5 = r_lld_con_ch_map_update(param_1,pvVar7,sVar3);
        if (iVar5 == 0) {
          llc_llcp_ch_map_update_ind_pdu_send(param_1,*(undefined2 *)(iVar4 + 0xe),pvVar7);
          r_llc_proc_state_set(iVar4,param_1,1);
          return;
        }
      }
    }
    else {
      if (iVar5 != 1) {
        uVar6 = r_llc_proc_state_get(iVar4);
        r_assert_param(param_1,uVar6,0x10000,0xcc);
        return;
      }
      memcpy((void *)(iVar2 + 8),(void *)(iVar4 + 8),5);
    }
  }
  *(ushort *)(iVar2 + 0x42) = *(ushort *)(iVar2 + 0x42) & 0xffef;
  r_llc_proc_unreg(param_1,0);
  *(ushort *)(iVar2 + 0x42) = *(ushort *)(iVar2 + 0x42) & 0xfeff;
  return;
}

