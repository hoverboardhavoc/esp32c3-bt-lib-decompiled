/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_set_adv_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_adv_data_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  void *__dest;
  int iVar5;
  byte abStack_21 [9];
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
    r_ble_log_internal_x1(0x802e00f2,0x212);
    uVar3 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    if (*param_1 < 0x20) {
      iVar4 = r_llm_adv_hdl_to_id(0xff,0);
      abStack_21[0] = (byte)iVar4;
      if (iVar4 == 0xff) {
        uVar3 = r_llm_activity_free_get(abStack_21);
        if (uVar3 != 0) {
          r_ble_log_internal_x1(0x802e00f4,(uint)abStack_21[0] << 8 | uVar3);
          goto _L284;
        }
        r_llm_adv_set_dft_params();
      }
      iVar4 = 0;
      sVar2 = *(short *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x28);
      if (*param_1 != 0) {
        iVar4 = r_ble_util_buf_adv_tx_alloc();
        bVar1 = *param_1;
        if (iVar4 == 0) {
          r_ble_log_internal_x1(0x802e00f5,(uint)bVar1 << 8 | 7);
          uVar3 = 7;
          goto _L284;
        }
        __dest = (void *)r_emi_get_mem_addr_by_offset();
        memcpy(__dest,param_1 + 1,(uint)bVar1);
      }
      iVar5 = *(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44;
      *(short *)(iVar5 + 0x28) = (short)iVar4;
      *(ushort *)(iVar5 + 0x2a) = (ushort)*param_1;
      if (*(char *)(iVar5 + 0x40) == '\x02') {
        r_lld_adv_adv_data_update_hack(iVar4);
      }
      else if (sVar2 != 0) {
        r_ble_util_buf_adv_tx_free(sVar2);
      }
      uVar3 = 0;
    }
    else {
      r_ble_log_internal_x1(0x802e00f3,(uint)*param_1 << 8 | 0x12);
      uVar3 = 0x12;
    }
  }
_L284:
  r_llm_cmd_cmp_send(param_2,uVar3);
  return 0;
}

