/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_rx_llcp_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_rx_llcp_check(int param_1,int param_2,int param_3,short param_4)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined4 uVar5;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(undefined2 *)((uint)bVar1 * 0x14 + 0x12 + iVar3);
  if (param_3 == 3) {
    puVar4 = (undefined2 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x20b,param_1 << 8 | 1,0xff,param_4 + 0xc,
                        *(code **)(_r_modules_funcs_p + 200));
    *(char *)(puVar4 + 1) = (char)param_4;
    iVar3 = _r_plf_funcs_p;
    puVar4[2] = uVar2;
    uVar5 = (**(code **)(iVar3 + 0xbc))(uVar2,*(code **)(iVar3 + 0xbc));
    uVar2 = *(undefined2 *)(param_2 + 0x7c);
    *(undefined4 *)(puVar4 + 4) = uVar5;
    *puVar4 = uVar2;
    iVar3 = _r_modules_funcs_p;
  }
  else {
    if (1 < (param_3 - 1U & 0xff)) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (param_3,param_1,"lld_con.c",0x86f,*(code **)(_r_plf_funcs_p + 0xc));
      return 1;
    }
    puVar4 = (undefined2 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x20d,param_1 << 8 | 1,0xff,0xc,*(code **)(_r_modules_funcs_p + 200));
    iVar3 = _r_plf_funcs_p;
    *puVar4 = uVar2;
    uVar5 = (**(code **)(iVar3 + 0xbc))(uVar2,*(code **)(iVar3 + 0xbc));
    iVar3 = _r_modules_funcs_p;
    *(undefined4 *)(puVar4 + 2) = uVar5;
    puVar4[4] = param_4;
    *(char *)(puVar4 + 5) = (char)param_3;
  }
  (**(code **)(iVar3 + 0xe0))(puVar4,*(code **)(iVar3 + 0xe0));
  *(ushort *)(param_2 + 0x84) = *(ushort *)(param_2 + 0x84) | 4;
  return 0;
}

