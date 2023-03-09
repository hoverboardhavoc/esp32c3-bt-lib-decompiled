/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
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
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined1 *puVar8;
  
  if (param_1 != 0) {
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
    if (((*(char *)(param_1 + 0x46) == '\x02') &&
        (iVar5 = iVar5 + (uint)*(byte *)(param_1 + 0x8e) * 2, *(char *)(iVar5 + 0x3d) == '\x02')) &&
       (uVar4 = (uint)*(ushort *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 0x7e) & 0xffff,
       (uVar4 - *(ushort *)(param_1 + 0x44) & 0xffff) < 0x7fff)) {
      bVar1 = *(byte *)(iVar5 + 0x3c);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar5 = (uint)bVar1 * 0xe;
      if (-1 < *(short *)(iVar6 + iVar5)) {
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        sVar2 = *(short *)(iVar6 + iVar5 + 4);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        if ((sVar2 != 0) && ((*(ushort *)(iVar5 + 2 + iVar6) & 3) == 3)) {
          pcVar7 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                     (sVar2,*(code **)(_r_plf_funcs_p + 0xbc));
          if (*pcVar7 == '\x01') {
            uVar3 = *(ushort *)(param_1 + 0x72);
            puVar8 = (undefined1 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))
                               (sVar2 + 6,*(code **)(_r_plf_funcs_p + 0xbc));
            iVar5 = (uVar3 + 1) * 9 + uVar4;
            iVar6 = iVar5 * 0x10000;
            *puVar8 = (char)((uint)iVar6 >> 0x10);
            puVar8[1] = (char)((uint)iVar5 >> 8);
            *(short *)(param_1 + 0x44) = (short)((uint)iVar6 >> 0x10);
            goto _L191;
          }
        }
        (**(code **)(_r_plf_funcs_p + 0xc))(0,0,"lld_con.c",0x541,*(code **)(_r_plf_funcs_p + 0xc));
      }
    }
  }
_L191:
  r_lld_con_evt_start_cbk(param_1);
  return;
}

