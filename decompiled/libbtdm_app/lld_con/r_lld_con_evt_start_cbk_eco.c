/*
 * Last changed at upstream commit a075a8fde411bdd92973051edf2cd234601b259c
 * https://github.com/espressif/esp32c3-bt-lib/commit/a075a8fde411bdd92973051edf2cd234601b259c
 * Upstream date: 2023-11-30 21:15:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(70ab55f)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_evt_start_cbk_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_start_cbk_eco(int param_1)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined1 *puVar7;
  
  if (param_1 != 0) {
    iVar4 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
    if (((*(char *)(param_1 + 0x46) == '\x02') &&
        (iVar4 = iVar4 + (uint)*(byte *)(param_1 + 0x8e) * 2, *(char *)(iVar4 + 0x3d) == '\x02')) &&
       (uVar3 = (uint)*(ushort *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 0x7e) & 0xffff,
       (uVar3 - *(ushort *)(param_1 + 0x44) & 0xffff) < 0x7fff)) {
      bVar1 = *(byte *)(iVar4 + 0x3c);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = (uint)bVar1 * 0xe;
      if (-1 < *(short *)(iVar5 + iVar4)) {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        sVar2 = *(short *)(iVar5 + iVar4 + 4);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        if ((sVar2 != 0) && ((*(ushort *)(iVar4 + 2 + iVar5) & 3) == 3)) {
          pcVar6 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                     (sVar2,*(code **)(_r_plf_funcs_p + 0xbc));
          if (*pcVar6 == '\x01') {
            iVar4 = *(ushort *)(param_1 + 0x72) + 9 + uVar3;
            iVar5 = iVar4 * 0x10000;
            puVar7 = (undefined1 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))
                               (sVar2 + 6,*(code **)(_r_plf_funcs_p + 0xbc));
            *puVar7 = (char)((uint)iVar5 >> 0x10);
            puVar7[1] = (char)((uint)iVar4 >> 8);
            *(short *)(param_1 + 0x44) = (short)((uint)iVar5 >> 0x10);
            goto _L192;
          }
        }
        (**(code **)(_r_plf_funcs_p + 0xc))(0,0,"lld_con.c",0x548,*(code **)(_r_plf_funcs_p + 0xc));
      }
    }
  }
_L192:
  r_lld_con_evt_start_cbk(param_1);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar4 + 0x19) == '\x02') {
                    /* WARNING: Could not recover jumptable at 0x00010ebc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x9dc))(param_1);
    return;
  }
  return;
}

