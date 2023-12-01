/*
 * Last changed at upstream commit f103dfec019fdd5bf9255abcaeaf20c707b26dc6
 * https://github.com/espressif/esp32c3-bt-lib/commit/f103dfec019fdd5bf9255abcaeaf20c707b26dc6
 * Upstream date: 2023-12-01 21:11:21 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b8f0db9)
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
  undefined1 uVar2;
  short sVar3;
  int iVar4;
  char *pcVar5;
  undefined1 *puVar6;
  undefined2 *puVar7;
  int iVar8;
  uint uVar9;
  
  if (param_1 != 0) {
    iVar4 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
    if (((*(char *)(param_1 + 0x46) == '\x02') &&
        (iVar4 = iVar4 + (uint)*(byte *)(param_1 + 0x8e) * 2, *(char *)(iVar4 + 0x3d) == '\x02')) &&
       (uVar9 = (uint)*(ushort *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 0x7e) & 0xffff,
       (uVar9 - *(ushort *)(param_1 + 0x44) & 0xffff) < 0x7fff)) {
      bVar1 = *(byte *)(iVar4 + 0x3c);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar8 = (uint)bVar1 * 0xe;
      if (-1 < *(short *)(iVar4 + iVar8)) {
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        sVar3 = *(short *)(iVar4 + iVar8 + 4);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        if ((sVar3 != 0) && ((*(ushort *)(iVar8 + 2 + iVar4) & 3) == 3)) {
          pcVar5 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                     (sVar3,*(code **)(_r_plf_funcs_p + 0xbc));
          if (*pcVar5 == '\x01') {
            iVar4 = *(ushort *)(param_1 + 0x72) + 9 + uVar9;
            iVar8 = iVar4 * 0x10000;
            puVar6 = (undefined1 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))
                               (sVar3 + 6,*(code **)(_r_plf_funcs_p + 0xbc));
            *puVar6 = (char)((uint)iVar8 >> 0x10);
            puVar6[1] = (char)((uint)iVar4 >> 8);
            *(short *)(param_1 + 0x44) = (short)((uint)iVar8 >> 0x10);
            goto _L193;
          }
        }
        if (0 < _g_bt_plf_log_level) {
          puVar6 = (undefined1 *)
                   (**(code **)(_r_plf_funcs_p + 0xbc))(sVar3,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar2 = *puVar6;
          puVar7 = (undefined2 *)
                   (**(code **)(_r_plf_funcs_p + 0xbc))(sVar3 + 6,*(code **)(_r_plf_funcs_p + 0xbc))
          ;
          ets_printf("llcp check: %u %u %u %u %u\n",uVar9,uVar2,*puVar7,
                     *(undefined1 *)(param_1 + 0x46),*(undefined2 *)(param_1 + 0x44));
        }
        (**(code **)(_r_ip_funcs_p + 0x7d4))
                  (*(undefined1 *)(param_1 + 0x8e),*(code **)(_r_ip_funcs_p + 0x7d4));
      }
    }
  }
_L193:
  r_lld_con_evt_start_cbk(param_1);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar4 + 0x19) == '\x02') {
                    /* WARNING: Could not recover jumptable at 0x00010ee6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x9dc))(param_1);
    return;
  }
  return;
}

