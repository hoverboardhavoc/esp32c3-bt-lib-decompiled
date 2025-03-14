/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_data_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_data_set
               (int param_1,undefined2 param_2,undefined2 param_3,int param_4,int param_5)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(&lld_per_adv_env + param_1 * 4);
  sVar1 = 0;
  if (param_4 != 0) {
    iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
    sVar1 = *(short *)(iVar2 + (param_1 * 9 & 0xffU) * 0xe + 4);
  }
  *(undefined2 *)(iVar3 + 0x50) = param_2;
  *(undefined2 *)(iVar3 + 0x4e) = param_3;
  r_lld_per_adv_chain_construct(*(undefined1 *)(iVar3 + 0x52));
  if ((param_4 != 0) && (sVar1 != 0)) {
    if (param_5 != 0) {
      r_ble_util_buf_adv_tx_free_in_isr();
      return;
    }
    r_ble_util_buf_adv_tx_free(sVar1);
    return;
  }
  return;
}

