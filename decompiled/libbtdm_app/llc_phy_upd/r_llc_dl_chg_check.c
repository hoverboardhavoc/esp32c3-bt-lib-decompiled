/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_phy_upd.o -> r_llc_dl_chg_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_dl_chg_check(uint param_1,int param_2,int param_3)

{
  char cVar1;
  undefined2 uVar2;
  bool bVar3;
  int iVar4;
  code *UNRECOVERED_JUMPTABLE;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  cVar1 = *(char *)(iVar5 + 0x1d);
  if (((*(char *)(iVar5 + 0x1c) == '\x03') == (param_2 == 3)) ||
     (uVar6 = (**(code **)(_r_modules_funcs_p + 4))
                        (*(char *)(iVar5 + 0x14) + '\x04',
                         (uint)(1 < (byte)(*(char *)(iVar5 + 0x1c) - 1U)) << 1,
                         *(code **)(_r_modules_funcs_p + 4)), *(ushort *)(iVar5 + 0x18) == uVar6)) {
    bVar3 = false;
    if ((cVar1 == '\x03') == (param_3 == 3)) {
      return;
    }
  }
  else {
    *(short *)(iVar5 + 0x18) = (short)uVar6;
    bVar3 = true;
    if ((cVar1 == '\x03') == (param_3 == 3)) goto _L166;
  }
  uVar6 = (**(code **)(_r_modules_funcs_p + 4))
                    (*(char *)(iVar5 + 0x16) + '\x04',(uint)(1 < (byte)(cVar1 - 1U)) << 1,
                     *(code **)(_r_modules_funcs_p + 4));
  if (*(ushort *)(iVar5 + 0x1a) == uVar6) {
    if (!bVar3) {
      return;
    }
  }
  else {
    *(short *)(iVar5 + 0x1a) = (short)uVar6;
  }
_L166:
  puVar7 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1104,param_1 & 0xffff,0x3e,0xc,*(code **)(_r_modules_funcs_p + 200));
  *puVar7 = 7;
  iVar4 = _r_ip_funcs_p;
  *(undefined2 *)(puVar7 + 8) = *(undefined2 *)(iVar5 + 0x16);
  uVar2 = *(undefined2 *)(iVar5 + 0x1a);
  *(short *)(puVar7 + 2) = (short)param_1;
  *(undefined2 *)(puVar7 + 10) = uVar2;
  *(undefined2 *)(puVar7 + 4) = *(undefined2 *)(iVar5 + 0x14);
  UNRECOVERED_JUMPTABLE = *(code **)(iVar4 + 0x8c);
  *(undefined2 *)(puVar7 + 6) = *(undefined2 *)(iVar5 + 0x18);
                    /* WARNING: Could not recover jumptable at 0x00010c86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

