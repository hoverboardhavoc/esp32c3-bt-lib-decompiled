/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_phy_upd.o -> r_llc_dl_chg_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_dl_chg_check(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  uVar5 = (uint)*(byte *)(iVar4 + 0x1d);
  if (((*(byte *)(iVar4 + 0x1c) == 3) == (param_2 == 3)) ||
     (uVar6 = (**(code **)(_r_modules_funcs_p + 4))
                        (*(short *)(iVar4 + 0x14) + 4U & 0xff,
                         (uint)(1 < *(byte *)(iVar4 + 0x1c) - 1) << 1,
                         *(code **)(_r_modules_funcs_p + 4)), *(ushort *)(iVar4 + 0x18) == uVar6)) {
    bVar2 = false;
    if ((uVar5 == 3) == (param_3 == 3)) {
      return;
    }
  }
  else {
    *(short *)(iVar4 + 0x18) = (short)uVar6;
    bVar2 = true;
    if ((uVar5 == 3) == (param_3 == 3)) goto _L173;
  }
  uVar5 = (**(code **)(_r_modules_funcs_p + 4))
                    (*(short *)(iVar4 + 0x16) + 4U & 0xff,(uint)(1 < uVar5 - 1) << 1,
                     *(code **)(_r_modules_funcs_p + 4));
  if (*(ushort *)(iVar4 + 0x1a) == uVar5) {
    if (!bVar2) {
      return;
    }
  }
  else {
    *(short *)(iVar4 + 0x1a) = (short)uVar5;
  }
_L173:
  puVar7 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1104,param_1,0x3e,0xc,*(code **)(_r_modules_funcs_p + 200));
  *puVar7 = 7;
  iVar3 = _r_ip_funcs_p;
  *(undefined2 *)(puVar7 + 8) = *(undefined2 *)(iVar4 + 0x16);
  *(undefined2 *)(puVar7 + 10) = *(undefined2 *)(iVar4 + 0x1a);
  *(undefined2 *)(puVar7 + 4) = *(undefined2 *)(iVar4 + 0x14);
  uVar1 = *(undefined2 *)(iVar4 + 0x18);
  *(short *)(puVar7 + 2) = (short)param_1;
  UNRECOVERED_JUMPTABLE = *(code **)(iVar3 + 0x8c);
  *(undefined2 *)(puVar7 + 6) = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00010c72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(UNRECOVERED_JUMPTABLE);
  return;
}

