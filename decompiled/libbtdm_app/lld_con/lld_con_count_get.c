/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> lld_con.o -> lld_con_count_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char lld_con_count_get(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = '\0';
  for (iVar2 = 0; iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
      iVar2 < (int)(uint)*(byte *)(iVar3 + 0xd); iVar2 = iVar2 + 1) {
    if (*(int *)(&lld_con_env + iVar2 * 4) != 0) {
      cVar1 = cVar1 + '\x01';
    }
  }
  return cVar1;
}

