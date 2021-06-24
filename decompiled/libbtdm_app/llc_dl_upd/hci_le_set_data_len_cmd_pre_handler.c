/*
 * Last changed at upstream commit b223604efd557d0a5314afb3b751229df424d244
 * https://github.com/espressif/esp32c3-bt-lib/commit/b223604efd557d0a5314afb3b751229df424d244
 * Upstream date: 2021-06-24 21:26:02 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (9c99115)
 * Source: libbtdm_app -> llc_dl_upd.o -> hci_le_set_data_len_cmd_pre_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int hci_le_set_data_len_cmd_pre_handler(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  iVar2 = 0;
  if (param_1 < *(byte *)(iVar1 + 0xd)) {
    iVar1 = *(int *)(&llc_env + param_1 * 4);
    iVar2 = 0;
    if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x44) & 3) != 3)) {
      iVar2 = (uint)((*(byte *)(iVar3 + 0x45) & 0x20) != 0) << 1;
    }
  }
  return iVar2;
}

