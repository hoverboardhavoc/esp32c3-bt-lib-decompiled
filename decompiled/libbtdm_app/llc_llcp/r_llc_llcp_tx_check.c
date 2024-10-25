/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_llcp.o -> r_llc_llcp_tx_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_llcp_tx_check(int param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  void *__dest;
  int iVar5;
  uint uVar6;
  byte bVar7;
  
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  if ((*(ushort *)(iVar3 + 0x42) & 2) == 0) {
    bVar1 = true;
    for (piVar2 = *(int **)(iVar3 + 0x28); piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      uVar6 = (int)(uint)*(byte *)(iVar3 + 0x44) >> 2 & 3;
      bVar7 = (&DAT_000108e6)[(uint)*(byte *)((int)piVar2 + 9) * 0xc];
      if (uVar6 == 2) {
        bVar7 = bVar7 >> 1;
      }
      else if (uVar6 == 3) {
        bVar7 = bVar7 >> 3;
      }
      else if (uVar6 == 1) {
        bVar7 = bVar7 >> 2;
      }
      if ((bVar7 & 1) != 0) {
        iVar4 = (**(code **)(_r_ip_funcs_p + 0xf4))(*(code **)(_r_ip_funcs_p + 0xf4));
        if (iVar4 == 0) {
          (**(code **)(_r_plf_funcs_p + 8))("llc_llcp.c",0x382,*(code **)(_r_plf_funcs_p + 8));
        }
        bVar7 = *(byte *)(piVar2 + 2);
        __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                   (*(undefined2 *)(iVar4 + 4),*(code **)(_r_plf_funcs_p + 0xbc));
        memcpy(__dest,(void *)((int)piVar2 + 9),(uint)bVar7);
        *(undefined1 *)(iVar4 + 6) = *(undefined1 *)(piVar2 + 2);
        *(ushort *)(iVar3 + 0x42) = *(ushort *)(iVar3 + 0x42) | 2;
        iVar5 = (**(code **)(_r_ip_funcs_p + 0x368))
                          (param_1,iVar4,*(code **)(_r_ip_funcs_p + 0x368));
        if (iVar5 == 0) {
          if (bVar1) {
            return;
          }
          (**(code **)(_r_modules_funcs_p + 0x1c))
                    (iVar3 + 0x28,piVar2,*(code **)(_r_modules_funcs_p + 0x1c));
                    /* WARNING: Could not recover jumptable at 0x0001082c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (**(code **)(_r_modules_funcs_p + 0x4c))(iVar3 + 0x28,piVar2);
          return;
        }
                    /* WARNING: Could not recover jumptable at 0x000107e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_ip_funcs_p + 0xf8))(*(undefined2 *)(iVar4 + 4));
        return;
      }
      bVar1 = false;
    }
  }
  return;
}

