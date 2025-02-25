/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_data_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_data_set(uint param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  short sVar3;
  
  iVar2 = *(int *)(&lld_per_adv_env + param_1 * 4);
  iVar1 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar1 + 0x28) & 0x40) != 0) {
    iVar1 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar1 + 0x2c) < 3) {
      r_ble_log_internal_x2
                (0x40080006,param_4 << 0x10 | param_2 << 8 | param_5 << 0x18 | param_1,param_3);
    }
  }
  sVar3 = 0;
  if (param_4 != 0) {
    iVar1 = r_emi_get_mem_addr_by_offset(0x1400);
    sVar3 = *(short *)(iVar1 + (param_1 * 9 & 0xff) * 0xe + 4);
  }
  *(short *)(iVar2 + 0x50) = (short)param_2;
  *(short *)(iVar2 + 0x4e) = (short)param_3;
  r_lld_per_adv_chain_construct(*(undefined1 *)(iVar2 + 0x52));
  if ((param_4 != 0) && (sVar3 != 0)) {
    if (param_5 != 0) {
      r_ble_util_buf_adv_tx_free_in_isr();
      return;
    }
    r_ble_util_buf_adv_tx_free(sVar3);
    return;
  }
  return;
}

