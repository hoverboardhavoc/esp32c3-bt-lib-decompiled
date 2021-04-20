/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> ble_util_buf.o -> r_ble_util_buf_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_util_buf_init(uint param_1)

{
  void *pvVar1;
  int iVar2;
  short *psVar3;
  short sVar4;
  
  if (param_1 == 0) {
    memset(_p_ble_util_buf_env,0,0x1bc);
    pvVar1 = _p_ble_util_buf_env;
    *(undefined1 *)((int)_p_ble_util_buf_env + 0x1ba) = 9;
    *(undefined2 *)((int)pvVar1 + 0x1b8) = 0x110;
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    pvVar1 = _p_ble_util_buf_env;
    psVar3 = (short *)((int)_p_ble_util_buf_env + 0xbc);
    *(undefined1 *)((int)_p_ble_util_buf_env + 0x1bb) = *(undefined1 *)(iVar2 + 0x10);
    sVar4 = 0x1e01;
    do {
      *psVar3 = sVar4;
      sVar4 = sVar4 + -0x1b;
      psVar3 = psVar3 + -4;
    } while (sVar4 != 0x1be5);
    for (iVar2 = (int)((*(byte *)((int)pvVar1 + 0x1ba) - 1) * 0x10000) >> 0x10; (short)iVar2 != -1;
        iVar2 = iVar2 + -1) {
      *(short *)((int)pvVar1 + iVar2 * 8 + 0xc4) = (short)(iVar2 << 10) + 0x7805;
    }
    psVar3 = (short *)((int)pvVar1 + 0x164);
    sVar4 = -0x3800;
    do {
      *psVar3 = sVar4;
      sVar4 = sVar4 + -0x400;
      psVar3 = psVar3 + -4;
    } while (sVar4 != -0x6800);
    *(undefined2 *)((int)pvVar1 + 0x1b4) = 0x6c00;
    *(undefined2 *)((int)pvVar1 + 0x1a4) = 0x5c00;
    *(undefined2 *)((int)pvVar1 + 0x1ac) = 0x6400;
    *(undefined2 *)((int)pvVar1 + 0x194) = 0x4c00;
    *(undefined2 *)((int)pvVar1 + 0x19c) = 0x5400;
    *(undefined2 *)((int)pvVar1 + 0x184) = 0x3c00;
    *(undefined2 *)((int)pvVar1 + 0x18c) = 0x4400;
    *(undefined2 *)((int)pvVar1 + 0x174) = 0x2c00;
    *(undefined2 *)((int)pvVar1 + 0x17c) = 0x3400;
    *(undefined2 *)((int)pvVar1 + 0x16c) = 0x2400;
  }
  else if (param_1 < 3) {
    (**(code **)(_r_modules_funcs_p + 0x3c))
              ((int)_p_ble_util_buf_env + 0x20,8,0x14,*(code **)(_r_modules_funcs_p + 0x3c));
    (**(code **)(_r_modules_funcs_p + 0x3c))
              ((int)_p_ble_util_buf_env + 8,(int)_p_ble_util_buf_env + 0xc0,8,
               *(undefined1 *)((int)_p_ble_util_buf_env + 0x1ba),
               *(code **)(_r_modules_funcs_p + 0x3c));
    (**(code **)(_r_modules_funcs_p + 0x3c))
              ((int)_p_ble_util_buf_env + 0x10,(int)_p_ble_util_buf_env + 0x108,8,0xc,
               *(code **)(_r_modules_funcs_p + 0x3c));
                    /* WARNING: Could not recover jumptable at 0x00010078. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x3c))
              ((int)_p_ble_util_buf_env + 0x18,(int)_p_ble_util_buf_env + 0x168,8,10);
    return;
  }
  return;
}

