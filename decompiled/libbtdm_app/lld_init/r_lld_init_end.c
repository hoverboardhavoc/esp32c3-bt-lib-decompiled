/*
 * Last changed at upstream commit a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * https://github.com/espressif/esp32c3-bt-lib/commit/a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * Upstream date: 2021-12-28 18:10:18 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (33175c8)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_end
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_end(void)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  while( true ) {
    iVar3 = iVar6 * 4;
    iVar5 = *(int *)(lld_init_env + iVar3);
    if (iVar5 != 0) {
      if (*(char *)(iVar5 + 0x31) == '\0') {
        (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar5,0,*(code **)(_r_ip_funcs_p + 0x6b8));
        (**(code **)(_r_ip_funcs_p + 0x718))(1,*(code **)(_r_ip_funcs_p + 0x718));
        (**(code **)(_r_modules_funcs_p + 0x110))
                  (*(undefined4 *)(lld_init_env + iVar3),*(code **)(_r_modules_funcs_p + 0x110));
        iVar5 = lld_init_env;
        *(undefined4 *)(iVar3 + lld_init_env) = 0;
        *(byte *)(iVar5 + 0x2b) = ~(byte)(1 << iVar6) & *(byte *)(iVar5 + 0x2b);
      }
      else if (*(char *)(iVar5 + 0x31) == '\x01') {
        bVar2 = *(byte *)(iVar5 + 0x52);
        iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)(iVar3 + (uint)bVar2 * 0x5a + 0x20) = 1;
        _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
        *(undefined1 *)(iVar5 + 0x31) = 2;
      }
    }
    if (iVar6 != 0) break;
    iVar6 = 1;
  }
  if (*(char *)(lld_init_env + 0x2b) == '\0') {
    if (*(int *)(lld_init_env + 8) == 0) {
      puVar4 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x209,0,0xff,0x38,*(code **)(_r_modules_funcs_p + 200));
      uVar1 = *(undefined1 *)(lld_init_env + 0x2c);
      puVar4[1] = 0;
      *puVar4 = uVar1;
    }
    (**(code **)(_r_modules_funcs_p + 0xe0))(*(code **)(_r_modules_funcs_p + 0xe0));
    (**(code **)(_r_modules_funcs_p + 0x110))(lld_init_env,*(code **)(_r_modules_funcs_p + 0x110));
    lld_init_env = 0;
  }
  return;
}

