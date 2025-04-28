/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> h4tl.o -> r_h4tl_out_of_sync_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_h4tl_out_of_sync_check(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 local_20;
  undefined1 auStack_1c [12];
  
  local_20 = 0xc0301;
  iVar1 = memcmp(&local_20,(void *)(param_1 + 0x10),4);
  if (iVar1 == 0) {
    (**(code **)(_r_ip_funcs_p + 0x2c))(0xc03,0,0,*(code **)(_r_ip_funcs_p + 0x2c));
  }
  else {
    memcpy(auStack_1c,&_LANCHOR0,10);
    iVar1 = memcmp(auStack_1c,(void *)(param_1 + 10),10);
    if (iVar1 != 0) {
      (**(code **)(_r_modules_funcs_p + 0x2b4))(4,*(code **)(_r_modules_funcs_p + 0x2b4));
      memmove((void *)(param_1 + 10),(void *)(param_1 + 0xb),9);
      return 0;
    }
    puVar2 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (1,8,0x1e,1,*(code **)(_r_modules_funcs_p + 200));
    *puVar2 = 1;
    (**(code **)(_r_modules_funcs_p + 0xe0))(*(code **)(_r_modules_funcs_p + 0xe0));
  }
  return 1;
}

