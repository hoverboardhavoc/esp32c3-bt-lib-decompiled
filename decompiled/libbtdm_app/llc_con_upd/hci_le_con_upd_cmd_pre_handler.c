/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> llc_con_upd.o -> hci_le_con_upd_cmd_pre_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_con_upd_cmd_pre_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  bVar1 = *param_1;
  iVar2 = *(int *)(&llc_env + (uint)bVar1 * 4);
  if (((iVar2 != 0) && (*(ushort *)(param_1 + 2) < 0xb)) &&
     ((uVar3 = lld_con_count_get(), 1 < uVar3 ||
      ((*(char *)(iVar2 + 0x1c) == '\x03' || (*(char *)(iVar2 + 0x1d) == '\x03')))))) {
    (**(code **)(_r_ip_funcs_p + 0x634))((uint)bVar1,param_2,0x12,*(code **)(_r_ip_funcs_p + 0x634))
    ;
    return 1;
  }
  return 0;
}

