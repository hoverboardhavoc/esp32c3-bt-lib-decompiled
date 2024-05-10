/*
 * Last changed at upstream commit 1a086eab61e78fa243d67c33206ece4022129ee1
 * https://github.com/espressif/esp32c3-bt-lib/commit/1a086eab61e78fa243d67c33206ece4022129ee1
 * Upstream date: 2024-05-10 19:28:08 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(eca46a0)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_end_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_end_hack(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 != 0) {
    if (((*(short *)(iVar1 + 0x24) != 0) && (*(short *)(iVar1 + 0x7e) != 0)) &&
       (*(short *)(iVar1 + 0x24) != *(short *)(iVar1 + 0x7e))) {
      if (((*(ushort *)(iVar1 + 0x74) & 0x10) == 0) || ((*(ushort *)(iVar1 + 0x74) & 0x14) == 0x10))
      {
        iVar2 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
        if (iVar2 == 0) {
          r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar1 + 0x7e));
        }
        else {
          (**(code **)(_r_ip_funcs_p + 0xdc))
                    (*(undefined2 *)(iVar1 + 0x7e),*(code **)(_r_ip_funcs_p + 0xdc));
        }
      }
    }
    if (((*(short *)(iVar1 + 0x26) != 0) && (*(short *)(iVar1 + 0x80) != 0)) &&
       (*(short *)(iVar1 + 0x26) != *(short *)(iVar1 + 0x80))) {
      if (((*(ushort *)(iVar1 + 0x74) & 0x12) == 2) || ((*(ushort *)(iVar1 + 0x74) & 0x14) == 0x10))
      {
        iVar2 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
        if (iVar2 == 0) {
          pcVar3 = *(code **)(_r_ip_funcs_p + 0xd8);
        }
        else {
          pcVar3 = *(code **)(_r_ip_funcs_p + 0xdc);
        }
        (*pcVar3)(*(undefined2 *)(iVar1 + 0x80),pcVar3);
      }
    }
  }
  r_lld_adv_end(param_1,param_2,param_3);
  return;
}

