/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_set_scan_rsp_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_scan_rsp_data_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  void *__dest;
  int iVar4;
  byte abStack_21 [9];
  
  iVar4 = 0xc;
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    iVar4 = 0x12;
    if (*param_1 < 0x20) {
      iVar4 = r_llm_adv_hdl_to_id(0xff,0);
      abStack_21[0] = (byte)iVar4;
      if (iVar4 == 0xff) {
        iVar4 = r_llm_activity_free_get(abStack_21);
        if (iVar4 != 0) goto _L296;
        r_llm_adv_set_dft_params(abStack_21[0],0);
      }
      iVar3 = 0;
      sVar2 = *(short *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x32);
      if (*param_1 != 0) {
        iVar3 = r_ble_util_buf_adv_tx_alloc();
        iVar4 = 7;
        if (iVar3 == 0) goto _L296;
        bVar1 = *param_1;
        __dest = (void *)r_emi_get_mem_addr_by_offset(7);
        memcpy(__dest,param_1 + 1,(uint)bVar1);
      }
      iVar4 = *(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44;
      *(short *)(iVar4 + 0x32) = (short)iVar3;
      *(ushort *)(iVar4 + 0x34) = (ushort)*param_1;
      if (*(char *)(iVar4 + 0x40) == '\x02') {
        r_lld_adv_scan_rsp_data_update(iVar3);
      }
      else if (sVar2 != 0) {
        r_ble_util_buf_adv_tx_free(sVar2);
      }
      iVar4 = 0;
    }
  }
_L296:
  r_llm_cmd_cmp_send(param_2,iVar4);
  return 0;
}

