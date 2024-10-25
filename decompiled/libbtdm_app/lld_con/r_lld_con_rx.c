/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_rx(int param_1,undefined4 param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  int iVar7;
  
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x820))(1,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x820));
  if (iVar4 == 0) {
    *(ushort *)(iVar3 + 0x84) = *(ushort *)(iVar3 + 0x84) & 0xfffb;
    while (iVar4 = (**(code **)(_r_ip_funcs_p + 0x2a4))(param_1,*(code **)(_r_ip_funcs_p + 0x2a4)),
          iVar4 != 0) {
      bVar1 = *(byte *)(_p_lld_env + 0xd8);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar7 = (uint)bVar1 * 0x14;
      uVar6 = *(ushort *)(iVar5 + iVar7 + 2);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar5 + iVar7 + 4);
      if (((uVar6 & 1) == 0) &&
         ((**(code **)(_r_ip_funcs_p + 0x39c))(param_1,iVar3,*(code **)(_r_ip_funcs_p + 0x39c)),
         (uVar6 & 8) == 0)) {
        *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(iVar3 + 0x50);
        if ((uVar6 & 0x66) == 0) {
          if ((uVar6 & 0x10) == 0) {
            iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            uVar6 = uVar2 >> 8;
            *(undefined2 *)(iVar3 + 0x98) = *(undefined2 *)(iVar5 + param_1 * 0x5a + 0x50);
            if ((uVar6 != 0) && ((uVar2 & 3) != 0)) {
              if ((4 < uVar6) && ((*(ushort *)(iVar3 + 0x84) & 0x20) != 0)) {
                uVar6 = uVar6 - 4;
              }
              iVar5 = (**(code **)(_r_ip_funcs_p + 0x394))
                                (param_1,iVar3,uVar6,*(code **)(_r_ip_funcs_p + 0x394));
              if (iVar5 == 0) {
                iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))
                                  (0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
                *(undefined2 *)(iVar7 + 0x12 + iVar5) = 0;
              }
            }
          }
          else {
            *(undefined1 *)(iVar3 + 0x8f) = 2;
            *(ushort *)(iVar3 + 0x84) = *(ushort *)(iVar3 + 0x84) | 0x80;
          }
        }
      }
      else {
        iVar4 = 0;
      }
      (**(code **)(_r_ip_funcs_p + 0x390))(iVar3,iVar4,*(code **)(_r_ip_funcs_p + 0x390));
      (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
    }
                    /* WARNING: Could not recover jumptable at 0x00011ed4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x820))(param_1,param_2);
    return;
  }
  return;
}

