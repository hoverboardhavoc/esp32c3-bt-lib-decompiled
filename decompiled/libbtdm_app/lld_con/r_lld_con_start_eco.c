/*
 * Last changed at upstream commit 7e73ebf92e5aa995065351043c13d2ac0f00772e
 * https://github.com/espressif/esp32c3-bt-lib/commit/7e73ebf92e5aa995065351043c13d2ac0f00772e
 * Upstream date: 2026-05-19 17:43:45 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(bc853c5)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_con_start_eco(uint param_1,undefined4 param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_21 [9];
  
  auStack_21[0] = 0xc;
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
  uVar3 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  *(undefined4 *)(iVar2 + 0x50) = uVar3;
  iVar4 = _r_ip_funcs_p;
  *(undefined2 *)(iVar2 + (param_1 + 0x10) * 2 + 8) = 0;
  (**(code **)(iVar4 + 0x7d8))(param_1,*(code **)(iVar4 + 0x7d8));
  (**(code **)(_r_ip_funcs_p + 0x7d4))(param_1,*(code **)(_r_ip_funcs_p + 0x7d4));
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x828))
                    (1,auStack_21,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x828));
  if (iVar4 == 0) {
    iVar4 = r_lld_con_start(param_1,param_2);
    auStack_21[0] = (undefined1)iVar4;
    if (iVar4 == 0) {
      iVar4 = *(int *)(&lld_con_env + param_1 * 4);
      if (iVar4 != 0) {
        *(undefined2 *)(iVar4 + 0x98) = 0xffff;
        *(undefined4 *)(lld_con_fake_rx + param_1 * 4) = 0;
        if ((byte)(*(char *)(iVar4 + 0x93) - 2U) < 2) {
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))("lld_con.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
          }
          puVar1 = (uint *)((param_1 + 0x1800c4cb) * 4);
          *puVar1 = *puVar1 & 0xfffffff0 | 0xe;
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
          }
          *puVar1 = *puVar1 & 0xdfffffff | 0x20000000;
        }
      }
    }
    (**(code **)(_r_ip_funcs_p + 0x828))
              (0,auStack_21,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x828));
  }
  return auStack_21[0];
}

