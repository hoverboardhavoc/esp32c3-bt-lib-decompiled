/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_test.o -> r_lld_test_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_evt_start_cbk(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  byte bStack_41;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  undefined1 uStack_26;
  undefined1 uStack_24;
  
  if (_lld_test_env != param_1) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x17f,*(code **)(_r_plf_funcs_p + 8));
  }
  if (param_1 != 0) {
    puVar4 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    uVar1 = *puVar4;
    (**(code **)(_r_ip_funcs_p + 0x214))(0,uVar1 & 0x1f,*(code **)(_r_ip_funcs_p + 0x214));
    (**(code **)(_r_modules_funcs_p + 0x1e0))
              (uVar1 & 0x1f,0,&bStack_41,&uStack_40,*(code **)(_r_modules_funcs_p + 0x1e0));
    if ((bStack_41 & 0xfe) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x82,*(code **)(_r_plf_funcs_p + 8));
    }
    puVar4 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    uVar1 = *puVar4;
    puVar4 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    *puVar4 = uVar1 & 0xff7f | (ushort)bStack_41 << 7;
    if (((byte)uStack_40 & 0xfe) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x8e,*(code **)(_r_plf_funcs_p + 8));
    }
    uVar2 = (ushort)(byte)uStack_40;
    puVar4 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    uVar1 = *puVar4;
    puVar4 = (ushort *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    iVar3 = _r_ip_funcs_p;
    uStack_40 = *(undefined4 *)(_r_ip_funcs_p + 0x204);
    *puVar4 = uVar1 & 0xffbf | uVar2 << 6;
    uStack_2b = 0;
    uStack_3c = *(undefined4 *)(param_1 + 4);
    uStack_28 = 0;
    uStack_38 = 0;
    uStack_34 = *(undefined4 *)(param_1 + 0x10);
    uStack_30 = 0;
    uStack_24 = 0;
    uStack_2c = *(undefined1 *)(param_1 + 0x16);
    uStack_26 = 0;
    uStack_2a = 0xf00;
    (**(code **)(iVar3 + 0x6c8))(&uStack_40,*(code **)(iVar3 + 0x6c8));
    *(undefined1 *)(param_1 + 0x2a) = 1;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000103a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x1ab,*(code **)(_r_plf_funcs_p + 8));
  return;
}

