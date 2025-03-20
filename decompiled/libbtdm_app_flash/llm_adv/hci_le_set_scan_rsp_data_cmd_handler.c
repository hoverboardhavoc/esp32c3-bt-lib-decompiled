/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
  void *__dest;
  int iVar3;
  int iVar4;
  byte abStack_21 [9];
  
  iVar3 = 0xc;
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    iVar3 = 0x12;
    if (*param_1 < 0x20) {
      iVar3 = r_llm_adv_hdl_to_id(0xff,0);
      abStack_21[0] = (byte)iVar3;
      if (iVar3 == 0xff) {
        iVar3 = r_llm_activity_free_get(abStack_21);
        if (iVar3 != 0) goto _L281;
        r_llm_adv_set_dft_params(abStack_21[0],0);
      }
      iVar4 = 0;
      sVar2 = *(short *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x32);
      if (*param_1 != 0) {
        iVar4 = r_ble_util_buf_adv_tx_alloc();
        iVar3 = 7;
        if (iVar4 == 0) goto _L281;
        bVar1 = *param_1;
        __dest = (void *)r_emi_get_mem_addr_by_offset(7);
        memcpy(__dest,param_1 + 1,(uint)bVar1);
      }
      iVar3 = *(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44;
      *(short *)(iVar3 + 0x32) = (short)iVar4;
      *(ushort *)(iVar3 + 0x34) = (ushort)*param_1;
      if (*(char *)(iVar3 + 0x40) == '\x02') {
        r_lld_adv_scan_rsp_data_update_hack(iVar4);
      }
      else if (sVar2 != 0) {
        r_ble_util_buf_adv_tx_free(sVar2);
      }
      iVar3 = 0;
    }
  }
_L281:
  r_llm_cmd_cmp_send(param_2,iVar3);
  return 0;
}

