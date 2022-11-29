/*
 * Last changed at upstream commit 79152b519023f26462498f3ef8805cff2a80e193
 * https://github.com/espressif/esp32c3-bt-lib/commit/79152b519023f26462498f3ef8805cff2a80e193
 * Upstream date: 2022-11-29 17:30:47 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(02bfb7f1) - Fixed lld_con.c line 3048 assert - Fixed crash sometimes when connected as a slave by the 8th device
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_evt_start_cbk_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_start_cbk_hack(int param_1)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  char *pcVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  
  if (((param_1 != 0) && (*(char *)(param_1 + 0x46) == '\x02')) &&
     (iVar7 = (uint)*(byte *)(param_1 + 0x8e) * 2, llcp_ind_info[iVar7 + 1] == '\x02')) {
    uVar8 = (uint)*(ushort *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 0x7e) & 0xffff;
    if ((uVar8 - *(ushort *)(param_1 + 0x44) & 0xffff) < 0x7fff) {
      bVar1 = llcp_ind_info[iVar7];
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar7 = (uint)bVar1 * 0xe;
      if (-1 < *(short *)(iVar4 + iVar7)) {
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        sVar2 = *(short *)(iVar4 + iVar7 + 4);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        if ((sVar2 != 0) && ((*(ushort *)(iVar7 + 2 + iVar4) & 3) == 3)) {
          pcVar5 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                     (sVar2,*(code **)(_r_plf_funcs_p + 0xbc));
          if (*pcVar5 == '\x01') {
            uVar3 = *(ushort *)(param_1 + 0x72);
            puVar6 = (undefined1 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))
                               (sVar2 + 6,*(code **)(_r_plf_funcs_p + 0xbc));
            iVar7 = (uVar3 + 1) * 9 + uVar8;
            iVar4 = iVar7 * 0x10000;
            *puVar6 = (char)((uint)iVar4 >> 0x10);
            puVar6[1] = (char)((uint)iVar7 >> 8);
            *(short *)(param_1 + 0x44) = (short)((uint)iVar4 >> 0x10);
            goto _L139;
          }
        }
        (**(code **)(_r_plf_funcs_p + 0xc))(0,0,"lld_con.c",0x4e5,*(code **)(_r_plf_funcs_p + 0xc));
      }
    }
  }
_L139:
  r_lld_con_evt_start_cbk(param_1);
  return;
}

