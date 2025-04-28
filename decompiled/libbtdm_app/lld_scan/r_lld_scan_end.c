/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_end
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_end(void)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  while( true ) {
    iVar5 = iVar6 * 4;
    iVar3 = *(int *)(_lld_scan_env + iVar5);
    if (iVar3 != 0) {
      (**(code **)(_r_ip_funcs_p + 0x3d8))(iVar3,1,*(code **)(_r_ip_funcs_p + 0x3d8));
      if (*(char *)(iVar3 + 0x3c) == '\0') {
        (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar3,0,*(code **)(_r_ip_funcs_p + 0x6b8));
        (**(code **)(_r_ip_funcs_p + 0x718))(0,*(code **)(_r_ip_funcs_p + 0x718));
        if (*(char *)(iVar3 + 0x3d) == '\x03') {
          iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
          if (*(char *)(iVar3 + 0x18) == '\0') {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x4aa,*(code **)(_r_plf_funcs_p + 8));
          }
          (**(code **)(_r_ip_funcs_p + 0x448))(iVar6,*(code **)(_r_ip_funcs_p + 0x448));
        }
        (**(code **)(_r_modules_funcs_p + 0x110))
                  (*(undefined4 *)(_lld_scan_env + iVar5),*(code **)(_r_modules_funcs_p + 0x110));
        iVar3 = _lld_scan_env;
        *(undefined4 *)(iVar5 + _lld_scan_env) = 0;
        *(byte *)(iVar3 + 0xc) = ~(byte)(1 << iVar6) & *(byte *)(iVar3 + 0xc);
      }
      else if (*(char *)(iVar3 + 0x3c) == '\x01') {
        bVar2 = *(byte *)(iVar3 + 0x38);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)((uint)bVar2 * 0x5a + 0x20 + iVar5) = 1;
        _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
        *(undefined1 *)(iVar3 + 0x3c) = 2;
      }
    }
    if (iVar6 != 0) break;
    iVar6 = 1;
  }
  if (*(char *)(_lld_scan_env + 0xc) == '\0') {
    puVar4 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x206,0,0xff,2,*(code **)(_r_modules_funcs_p + 200));
    uVar1 = *(undefined1 *)(_lld_scan_env + 0xd);
    *puVar4 = 0;
    puVar4[1] = uVar1;
    (**(code **)(_r_modules_funcs_p + 0xe0))(*(code **)(_r_modules_funcs_p + 0xe0));
    (**(code **)(_r_modules_funcs_p + 0x110))(_lld_scan_env,*(code **)(_r_modules_funcs_p + 0x110));
    _lld_scan_env = 0;
  }
  return;
}

